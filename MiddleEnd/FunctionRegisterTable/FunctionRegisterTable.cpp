#include "FunctionRegisterTable.h"

namespace MiddleEnd {

void TypeInfo::sanity_check() const
{
    // 检查基础类型信息合法性
    die_if_error(base_type == "int" || base_type == "float" || \
        base_type == "void", make_error_message("base_type not 'int' or 'float' or 'void'"));

    // 检查构造类型信息合法性
    die_if_error(construct_type == "array" || construct_type == "pointer" \
        || construct_type == "none", make_error_message("construct_type not 'none' or 'array' or 'pointer'"));

    // 空类型不能构造数组或指针
    if(base_type == "void") {
        die_if_error(construct_type == "none", make_error_message("construct_type for base_type 'void' must be 'none'"));
    }

    // 非构造类型不能有数组下标信息
    if(construct_type == "none") {
        die_if_error(index_info.size() == 0, make_error_message("index_info.size() should == 0 for construct_type 'none'"));
    }

    // 检查数组长度信息合法性
    if(construct_type == "array" || construct_type == "pointer") {
        die_if_error(index_info.size() >= 1, make_error_message(("construct_type " + \
            construct_type + " index_info.size() should >= 1").c_str()));
        // 数组的每一维长度都应该大于零
        if(construct_type == "array") {
            for(auto len: index_info) {
                die_if_error(len > 0, make_error_message("array length should > 0"));
            }
        }else {
            // 指针的第一维长度等于零
            die_if_error(index_info[0] == 0, make_error_message("pointer length (first dimension) should == 0"));

            // 其他维度长度大于零
            for(int i = 1; i < index_info.size(); i += 1) {
                die_if_error(index_info[i] > 0, make_error_message("pointer length (after first dimension) should > 0"));
            }
        }
    }else {
        // 非数组类型数组不应该有数组长度信息
        die_if_error(index_info.size() == 0, make_error_message("construct type none index_info.size() should == 0"));
    }
}

String TypeInfo::get_type_info_string() const {
    sanity_check();
    if(construct_type == "none") {
        return base_type;
    }else {
        String ans = base_type;
        if(construct_type == "pointer") {
            ans += "[]";
        }
        for(int i = 0; i < index_info.size(); i += 1) {
            if(index_info[i] > 0) {
                ans += "[" + std::to_string(index_info[i]) + "]";
            }
        }
        return ans;
    }
}

bool LocalScope::variable_exist(String variable_name) {
    return name_to_info.count(variable_name) > 0;
}

VariableInfo LocalScope::get_variable_info_by_name(String variable_name) {
    die_if_error(variable_exist(variable_name), make_error_message("variable_name not found"));
    return name_to_info[variable_name];
}

void FunctionRegisterTable::init_system_lib_function() {
    // TODO: 为 lib 中的函数进行初始化
}

} // namespace MiddleEnd;

#ifdef TEST_FUNCTION_REGISTER_TABLE
int main() {
    MiddleEnd::TypeInfo type_info = {
        .base_type      = "int",
        .construct_type = "array",
        .index_info     = {5, 1, 2, 3, 4}
    };
    std::cout << type_info.get_type_info_string() << std::endl;
    return 0;
}
#endif
