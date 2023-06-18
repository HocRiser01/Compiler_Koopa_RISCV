//
// Created by yyi on 2023/6/12.
//

#include "koopa.h"
#include "KoopaWalker.h"
#include "../ErrorMessage.h"

#define debugf printf
#define assert(x) die_if_error(x, "assert error")
#define assembly_code asm_code
#define REMOVE_SYMBOL(x) ((x)+1)
#define ull unsigned long long
#define max(a, b) ((a) > (b) ? (a) : (b))
typedef std::string String;

//inline std::string remove_sym(const char* str) {
//    if(str == nullptr) {
//        puts("Fuck!");
//        return String("Nop");
//    }
//    std::string s = str;
//    return s.substr(1);
//}
std::stringstream asm_code;
RegisterAllocator allocator;
uint8_t my_sp;
uint8_t stack_size;
String my_func;
/* 下 面 是 实 际 工 作 函 数*/

// 统计当前函数栈长度
inline void get_stack_size(const koopa_raw_function_t &func) {
    stack_size = 0;
    auto bbs = func->bbs;
    int max_call_a = 0, has_call = 0, allocs = 0;
    for(int i = 0; i < func->bbs.len; i ++ ) {
        auto bb = reinterpret_cast<koopa_raw_basic_block_t>(bbs.buffer[i]);
        auto insts = bb->insts;
        for (int j = 0; j < bb->insts.len; j ++ ) {
            koopa_raw_value_t inst = reinterpret_cast<koopa_raw_value_t>(insts.buffer[j]);
            switch(inst->kind.tag) {
                case KOOPA_RVT_CALL :
                    max_call_a = max(int(inst->kind.data.call.args.len)-8, max_call_a);
                    has_call = 1;
                case KOOPA_RVT_LOAD:
                case KOOPA_RVT_BINARY:
                case KOOPA_RVT_ALLOC :
                    allocs ++;
                    break;
                default:
                    continue;
            }
        }
    }
    debugf("Func %s, stack %d(alloc %d, has_call : %d, max_call_a %d)\n", func->name, stack_size, allocs, has_call, max_call_a);
    // 15 for ceil
    stack_size = allocs * 4 + has_call * 4 + max_call_a * 4 + 15;
    stack_size &= ~15;
}
void VisitGlobal(const koopa_raw_slice_t &global) {
    asm_code << "  .data\n";
    for(int i = 0; i < global.len; i ++ ) {
        koopa_raw_value_t  data = reinterpret_cast<koopa_raw_value_t>(global.buffer[i]);
        asm_code << "  .globl " << REMOVE_SYMBOL(data->name) << '\n';
        asm_code << REMOVE_SYMBOL(data->name) << ":\n";
        switch(data->kind.data.global_alloc.init->kind.tag) {
            case KOOPA_RVT_INTEGER:
                asm_code << "  .word " << data->kind.data.global_alloc.init->kind.data.integer.value << '\n';
                break;
            case KOOPA_RVT_GLOBAL_ALLOC:
                break;
            case KOOPA_RVT_ZERO_INIT:
                break;
            default:
                break;
        }
    }
}
// 访问 raw program
std::string Visit(const koopa_raw_program_t &program) {
    // 访问所有全局变量
    VisitGlobal(program.values);
    // 访问所有函数
    asm_code << "  .text\n";
    Visit(program.funcs);
    std::cout << asm_code.str() << "\n";
    return asm_code.str();
}
void Visit(const koopa_raw_slice_t &slice) {
    for (size_t i = 0; i < slice.len; ++i) {
        auto ptr = slice.buffer[i];
        // 根据 slice 的 kind 决定将 ptr 视作何种元素
        switch (slice.kind) {
            case KOOPA_RSIK_FUNCTION:
                // 访问函数
                Visit(reinterpret_cast<koopa_raw_function_t>(ptr));
                break;
            case KOOPA_RSIK_BASIC_BLOCK:
                // 访问基本块
                Visit(reinterpret_cast<koopa_raw_basic_block_t>(ptr));
                break;
            case KOOPA_RSIK_VALUE:
                Visit(reinterpret_cast<koopa_raw_value_t>(ptr));
                break;
            default:
                // 我们暂时不会遇到其他内容, 于是不对其做任何处理
                break;
        }
    }
}
void Visit(const koopa_raw_function_t &func) {
    my_sp = 0;
    my_func = REMOVE_SYMBOL(func->name);
    asm_code << "  .global " << REMOVE_SYMBOL(func->name) << "\n";
    asm_code << REMOVE_SYMBOL(func->name) << ":\n";
    get_stack_size(func);
    asm_code << "  addi sp, sp, -" << std::to_string(stack_size) << '\n';
    asm_code << "  sw ra, " << std::to_string(stack_size-4) << "(sp)\n";
    Visit(func->bbs);
    asm_code << "  lw ra, " << std::to_string(stack_size-4) << "(sp)\n";
    asm_code << "  addi sp, sp, " << std::to_string(stack_size) << '\n';
    asm_code << "  ret\n";
    asm_code << std::endl;
}
void Visit(const koopa_raw_basic_block_t &bb) {
    asm_code << my_func << REMOVE_SYMBOL(bb->name) << ":\n";
    Visit(bb->insts);
}
void Visit(const koopa_raw_return_t &ret) {
    if (!ret.value) {
        asm_code << "  li a0, 0\n";
    }
    if (ret.value != nullptr) {
        // 检查是否为立即数 (如：整数常量)
        if (ret.value->kind.tag == KOOPA_RVT_INTEGER) {
            // 将立即数加载到 a0 寄存器
            asm_code << "  li a0, " << ret.value->kind.data.integer.value << '\n';
        } else if (&(ret.value->kind.data) != nullptr) {
            // return %0
            debugf("Return From %p\n", &(ret.value->kind.data));
            String temp = allocator.Allocate();
            asm_code << "  lw " << temp << ", " << allocator.Get((ull)&(ret.value->kind.data)) << "(sp)" << '\n';
            asm_code << "  mv a0, " <<  temp << '\n';
            allocator.Deallocate(temp);
        } else {
            debugf("[Return] Unknown %p\n", &ret.value->kind.data);
        }
    } else {
        debugf("[Return] Null\n");
    }

}
void LoadValue(koopa_raw_value_t l, koopa_raw_value_t r, String &lreg, String &rreg, String &res) {
   // debugf("[LoadValue] %s %s\n", l->name, r->name);
    if(l->kind.tag == KOOPA_RVT_INTEGER) {
        if(l->kind.data.integer.value == 0) {
            lreg = "x0";
        } else {
            lreg = allocator.Allocate();
            asm_code << "  li " << lreg << ", " << l->kind.data.integer.value << '\n';
            res = lreg;
        }
    } else {
        lreg = allocator.Allocate();
        String temp = allocator.Get((ull)&(l->kind.data));
        asm_code << "  lw " << lreg << ", " << temp << "(sp)" << '\n';
    }

    if(r->kind.tag == KOOPA_RVT_INTEGER) {
        if(r->kind.data.integer.value == 0) {
            rreg = "x0";
        } else {
            rreg = allocator.Allocate();
            asm_code << "  li " << rreg << ", " << r->kind.data.integer.value << '\n';
            res = rreg;
        }
    } else {
        rreg = allocator.Allocate();
        debugf("Extract rhs from %p\n", &r);
        String temp = allocator.Get((ull)&(r->kind.data));
        asm_code << "  lw " << rreg << ", " << temp << "(sp)" << '\n';
    }
    return;
}
void GenerateEq(String res, String lhs, String rhs) {
    asm_code << "  xor " << res << ", " << lhs << ", " << rhs << '\n';
    asm_code << "  seqz " << res << ", " << res << '\n';
}
void GenerateLe(String res, String lhs, String rhs) {
    asm_code << "  sgt " << res << ", " << lhs << ", " << rhs << '\n';
    asm_code << "  seqz " << res << ", " << res << '\n';
}
inline void GenerateNormal(String op, String res, String lhs, String rhs) {
    asm_code << "  " << op << " " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateSub(String res, String lhs, String rhs) {GenerateNormal("sub", res, lhs, rhs);}
void GenerateMul(String res, String lhs, String rhs) {GenerateNormal("mul", res, lhs, rhs);}
void GenerateAdd(String res, String lhs, String rhs) {GenerateNormal("add", res, lhs, rhs);}
void GenerateNeq(std::string res, std::string lhs, std::string rhs) {
    GenerateEq(res, lhs, rhs);
    assembly_code << "  seqz " << res << ", " << res << '\n';
}
void GenerateGt(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  slt " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateGe(std::string res, std::string lhs, std::string rhs) {
    GenerateLe(res, lhs, rhs);
    assembly_code << "  seqz " << res << ", " << res << '\n';
}
void GenerateDiv(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  div " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateMod(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  rem " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateAnd(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  and " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateOr(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  or " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateXor(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  xor " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateShl(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  sll " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateShr(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  srl " << res << ", " << lhs << ", " << rhs << '\n';
}
void GenerateSar(std::string res, std::string lhs, std::string rhs) {
    assembly_code << "  sra " << res << ", " << lhs << ", " << rhs << '\n';
}
void Visit(const koopa_raw_binary_t &binary) {
    debugf("[BinaryOp] %p %p %p\n", &binary.lhs->kind.data, &binary.rhs->kind.data, &binary);
//    debugf("[BinaryOp] %d\n", binary.rhs->ty->tag);
    String lhs, rhs, res = "";
    LoadValue(binary.lhs, binary.rhs, lhs, rhs, res);
    if (res == "") res = allocator.Allocate();
    switch (binary.op) {
        case KOOPA_RBO_EQ:
            GenerateEq(res, lhs, rhs);
            break;
        case KOOPA_RBO_SUB:
            GenerateSub(res, lhs, rhs);
            break;
        case KOOPA_RBO_ADD:
            GenerateAdd(res, lhs, rhs);
            break;
        case KOOPA_RBO_MUL:
            GenerateMul(res, lhs, rhs);
            break;
        case KOOPA_RBO_LE:
            GenerateLe(res, lhs, rhs);
            break;
        case KOOPA_RBO_NOT_EQ:
            GenerateNeq(res, lhs, rhs);
            break;

        case KOOPA_RBO_GT:
            GenerateGt(res, lhs, rhs);
            break;

        case KOOPA_RBO_GE:
            GenerateGe(res, lhs, rhs);
            break;

        case KOOPA_RBO_DIV:
            GenerateDiv(res, lhs, rhs);
            break;

        case KOOPA_RBO_MOD:
            GenerateMod(res, lhs, rhs);
            break;

        case KOOPA_RBO_AND:
            GenerateAnd(res, lhs, rhs);
            break;

        case KOOPA_RBO_OR:
            GenerateOr(res, lhs, rhs);
            break;

        case KOOPA_RBO_XOR:
            GenerateXor(res, lhs, rhs);
            break;

        case KOOPA_RBO_SHL:
            GenerateShl(res, lhs, rhs);
            break;

        case KOOPA_RBO_SHR:
            GenerateShr(res, lhs, rhs);
            break;

        case KOOPA_RBO_SAR:
            GenerateSar(res, lhs, rhs);
            break;
        default:
            die_if_error(false, make_error_message("no such bin_op"));
    }
    asm_code << "  sw " << res << ", " << std::to_string(my_sp) << "(sp)" << '\n';
    allocator.Deallocate(res);
    allocator.Deallocate(lhs);
    allocator.Deallocate(rhs);
    debugf("Bin_OP Save to %p\n", &binary);
    allocator.Set((ull)&binary, std::to_string(my_sp));
    my_sp += 4;

}
void Visit(const koopa_raw_store_t &store) {
    auto value = store.value;
    auto dest = store.dest;
    String temp_addr = allocator.Allocate(), temp = allocator.Allocate();
    if (value->kind.tag == KOOPA_RVT_INTEGER) {
        asm_code << "  li " << temp << ", " << value->kind.data.integer.value << '\n';
    } else if(value->kind.tag == KOOPA_RVT_FUNC_ARG_REF) {
        auto arg = value->kind.data.func_arg_ref;
        if (arg.index < 8) {
            asm_code << "  mv " << temp << ", a" << arg.index << '\n';
        } else {
            asm_code << "  li " << temp_addr << ", " << stack_size + (arg.index-8) * 4 << '\n';
            asm_code << "  add " << temp_addr << ", " << temp_addr << ", sp\n";
            asm_code << "  lw " << temp << ", (" << temp_addr << ")\n";
        }
    } else {
        asm_code << "  lw " << temp << ", " << allocator.Get((ull)&store.value->kind.data) << "(sp)" << '\n';
    }

    String addr = allocator.Get((ull)&(dest->kind.data));
    if (addr == "NULL") {
        debugf("ALLOCATING FOR %p %d\n", &(dest->kind.data), my_sp);
        addr = std::to_string(my_sp);
        allocator.Set((ull)&(dest->kind.data), addr);
        my_sp += 4;
    }
    asm_code << "  sw " << temp << ", " << addr << "(sp)" << '\n';
    allocator.Deallocate(temp);
    allocator.Deallocate(temp_addr);
}
void Visit(const koopa_raw_load_t &load) {
    debugf("LOADING FOR %p, TO %p, Kind %d\n", &(load.src), &(load.src->kind.data), load.src->kind.tag);
    String temp = allocator.Allocate(), temp_addr = allocator.Allocate();
    switch (load.src->kind.tag) {
        case KOOPA_RVT_GET_PTR:
            break;
        case KOOPA_RVT_GET_ELEM_PTR:
            break;
        case KOOPA_RVT_GLOBAL_ALLOC:
            asm_code << "  la " << temp_addr << ", " << REMOVE_SYMBOL(load.src->name) << '\n';
            asm_code << "  lw " << temp << ", (" << temp_addr << ")\n";
            asm_code << "  li " << temp_addr << ", " << std::to_string(my_sp) << '\n';
            asm_code << "  add " << temp_addr << ", " << temp_addr << ", sp\n";
            asm_code << "  sw " << temp << ", (" << temp_addr << ")\n";
            allocator.Set((ull)&(load.src), std::to_string(my_sp));
            my_sp += 4;
            break;
        default:
            allocator.Set((ull)&(load.src), allocator.Get((ull)&(load.src->kind.data)));
            break;
    }
    allocator.Deallocate(temp); allocator.Deallocate(temp_addr);
}
void Visit(const koopa_raw_jump_t &jump) {
    asm_code << "  j " << my_func << REMOVE_SYMBOL(jump.target->name) << '\n';
    asm_code << std::endl;
}
void Visit(const koopa_raw_branch_t &branch) {
    String cond_addr = allocator.Allocate(), cond = allocator.Allocate();

    asm_code << "  li " << cond_addr << ", " << allocator.Get((ull)&(branch.cond->kind.data)) << '\n';
    asm_code << "  add " << cond_addr << ", " << cond_addr << ", sp" << '\n';
    asm_code << "  lw " << cond << ", (" << cond_addr << ")\n";
    asm_code << "  beqz " << cond << ", j_" << my_func <<REMOVE_SYMBOL(branch.false_bb->name) << '\n';
    asm_code << "  bnez " << cond << ", j_" << my_func << REMOVE_SYMBOL(branch.true_bb->name) << '\n';
    asm_code << "j_" << my_func << REMOVE_SYMBOL(branch.false_bb->name) << ":\n";
    asm_code << "  j " << my_func << REMOVE_SYMBOL(branch.false_bb->name) << '\n';
    asm_code << "j_" << my_func << REMOVE_SYMBOL(branch.true_bb->name) << ":\n";
    asm_code << "  j " << my_func << REMOVE_SYMBOL(branch.true_bb->name) << '\n';

    asm_code << std::endl;

}
void Visit(const koopa_raw_call_t &call) {
    debugf("CALL %p\n", &call);
    auto func = call.callee;
    auto args = call.args;
    String temp = allocator.Allocate();
    uint8_t arg_sp = 0;
    for(int i = 0; i < args.len; i ++ ) {
        auto arg_val = reinterpret_cast<koopa_raw_value_t>(args.buffer[i]);
        String addr = allocator.Get((ull)&(arg_val->kind.data));
        if(addr != "NULL") {
            asm_code << "  li " << temp << ", " << addr << '\n';
            asm_code << "  add " << temp << ", " << temp << ", sp\n";
            if(i < 8) {
                asm_code << "  lw a" << i << ", (" << temp << ")\n";
            } else {
                String temp2 = allocator.Allocate();
                asm_code << "  lw " << temp2 << ", (" << temp << ")\n";
                asm_code << "  li " << temp << ", " << std::to_string(arg_sp) << '\n';
                asm_code << "  add " << temp << ", " << temp << ", sp\n";
                asm_code << "  sw " << temp2 << ", (" << temp << ")\n";
                my_sp += 4;
                allocator.Deallocate(temp2);
            }
        } else if(arg_val->kind.tag == KOOPA_RVT_INTEGER) {
            asm_code << "  li " << temp << ", " << arg_val->kind.data.integer.value << '\n';
            if(i < 8) {
                asm_code << "  mv a" << i << ", " << temp << "\n";
            } else {
                String temp_addr = allocator.Allocate();
                asm_code << "  li " << temp_addr << ", " << std::to_string(arg_sp) << '\n';
                asm_code << "  add " << temp_addr << ", " << temp_addr << ", sp\n";
                asm_code << "  sw " << temp << ", (" << temp_addr << ")\n";
                my_sp += 4;
                allocator.Deallocate(temp_addr);
            }
        } else {
            die_if_error(false, make_error_message("No such arg"));
        }
    }
    String temp_addr = allocator.Allocate();
    allocator.Deallocate(temp_addr);
    asm_code << "  call " << REMOVE_SYMBOL(func->name) << '\n';
    allocator.Set((ull)&(call), std::to_string(my_sp));
    asm_code << "  li " << temp << ", " << std::to_string(my_sp) << '\n';
    asm_code << "  add " << temp << ", " << temp << ", sp\n";
    asm_code << "  sw a0, (" << temp << ")\n";
    my_sp += 4;
    allocator.Deallocate(temp);
}
void Visit(const koopa_raw_global_alloc_t &alloc) {
    asm_code << "  .data\n";

}
void Visit(const koopa_raw_value_t &value) {
    const auto &kind = value->kind;
    debugf("val : %p %d\n", &value, value->kind.tag);
    switch (kind.tag) {
        case KOOPA_RVT_RETURN:
            // 访问 return 指令
            Visit(kind.data.ret);
            break;
        case KOOPA_RVT_BINARY:
            // 访问 binary 指令
            Visit(kind.data.binary);
            break;
        case KOOPA_RVT_STORE:
            Visit(kind.data.store);
            break;
        case KOOPA_RVT_ALLOC:
            debugf("ALLOC %p\n", &value);
            break;
        case KOOPA_RVT_LOAD:
            Visit(kind.data.load);
            break;
        case KOOPA_RVT_JUMP:
            Visit(kind.data.jump);
            break;
        case KOOPA_RVT_BRANCH:
            Visit(kind.data.branch);
            break;
        case KOOPA_RVT_CALL:
            Visit(kind.data.call);
            break;
        default:
            // 其他类型暂时遇不到
            debugf("Type : %d\n", kind.tag);
            die_if_error(false, make_error_message("inst unknown"));
    }
}
