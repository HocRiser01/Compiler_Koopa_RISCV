#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <type_traits>
#include "IrGenerator.h"
#include "../ErrorMessage.h"

#define cur_type obj_manager -> get_type(cur_node_idx)
#define cur_info obj_manager -> get_info(cur_node_idx)
#define cur_list obj_manager -> get_son_uuid_list(cur_node_idx)
#define son_num cur_list.size()
#define first_son cur_list[0]
#define second_son cur_list[1]
#define third_son cur_list[2]
#define first_son_type obj_manager -> get_type(first_son)
#define first_son_info obj_manager -> get_info(first_son)
#define second_son_type obj_manager -> get_type(second_son)
#define second_son_info obj_manager -> get_info(second_son)
#define FIRST visit_ast(obj_manager, first_son)
#define SECOND visit_ast(obj_manager, second_son)
#define THIRD visit_ast(obj_manager, third_son)
#define calc_first calc<T>(obj_manager, first_son)
#define calc_second calc<T>(obj_manager, second_son)
#define calc_third calc<T>(obj_manager, third_son)

#define WRONG die_if_error(false, make_error_message(cur_type))

namespace MiddleEnd {

const String FLOAT = "float"; // 未约定

static int var_cnt = 0, block_cnt = 0, now_end, now_entry, stk_top = 0;
static int flag = 0; // array_IR()
static int btype; // ConstDef
static int param_type; // FuncFParam
std::map<int, std::map<String, String>> symbol_table; // 符号表
std::map<int, std::map<String, int>> const_int; // 整数常数表
std::map<int, std::map<String, float>> const_float; // 浮点常数表
std::map<int, std::map<String, int>> value_type; // 0：变量或常量，1：数组，2：数组指针
std::vector <String> call_params;

template <typename T>
T calc(ObjTree::ObjManager* obj_manager, ObjTree::ObjUuid cur_node_idx){ // 常量表达式计算
    // std::cout << "_ " << cur_type << " " << cur_info << std::endl;

    if (cur_type == "ExpAst"){
        if (son_num != 1) WRONG;
        return calc_first;
    }

    if (cur_type == "MulExpAst") {
        if (son_num == 1) return calc_first;
        else if (son_num == 3){
            String Op = second_son_info;
            if (Op == "*"){
                int t1 = calc_first, t2 = calc_third;
                // std::cout << t1 << " * " << t2 << " = " << t1 * t2 << std::endl;
                return t1 * t2;
            }else if (Op == "/"){
                int t1 = calc_first, t2 = calc_third;
                // std::cout << t1 << " / " << t2 << " = " << t1 / t2 << std::endl;
                return t1 / t2;
            }else if (Op == "%"){
                int t1 = calc_first, t2 = calc_third;
                // std::cout << t1 << " % " << t2 << " = " << t1 % t2 << std::endl;
                return t1 % t2;
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "AddExpAst"){
        if (son_num == 1) return calc_first;
        else if (son_num == 3){
            String Op = second_son_info;
            if (Op == "+"){
                int t1 = calc_first, t2 = calc_third;
                // std::cout << t1 << " + " << t2 << " = " << t1 + t2 << std::endl;
                return t1 + t2;
            }else if (Op == "-"){
                int t1 = calc_first, t2 = calc_third;
                // std::cout << t1 << " - " << t2 << " = " << t1 - t2 << std::endl;
                return t1 - t2;
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "RelExpAst"){
        if (son_num == 1) return calc_first;
        else if (son_num == 3){
            String Op = second_son_info;
            if (Op == "<"){
                int t1 = calc_first, t2 = calc_third;
                return t1 < t2;
            }else if (Op == "<="){
                int t1 = calc_first, t2 = calc_third;
                return t1 <= t2;
            }else if (Op == ">"){
                int t1 = calc_first, t2 = calc_third;
                return t1 > t2;
            }else if (Op == ">="){
                int t1 = calc_first, t2 = calc_third;
                return t1 >= t2;
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "RelExpAst"){
        if (son_num == 1) return calc_first;
        else if (son_num == 3){
            String Op = second_son_info;
            if (Op == "=="){
                int t1 = calc_first, t2 = calc_third;
                return t1 == t2;
            }else if (Op == "!="){
                int t1 = calc_first, t2 = calc_third;
                return t1 != t2;
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "UnaryExpAst"){
        if (son_num == 1 && cur_info == "") return calc_first;
        else if (son_num == 0) WRONG;
        else if (son_num == 1 && cur_info != "") WRONG;
        else if (son_num == 2){
            if (first_son_info == "+") return calc_second;
            else if (first_son_info == "-") return -calc_second;
            else if (first_son_info == "!") return -1 - calc_second;
        }
    }

    if (cur_type == "PrimaryExpAst"){
        if (son_num != 1) WRONG;
        if (first_son_type == "ExpAst") return calc_first;
        else if (first_son_type == "LValAst"){
            int k = stk_top;
            for (; k >= 0; k --){
                if (const_int[k].find(first_son_info) != const_int[k].end()){
                    return const_int[k][first_son_info];
                }
            }
            // if (std::is_same<T, int>){
            //     int k = stk_top;
            //     for (; k >= 0; k --){
            //         if (const_int[k].find(first_son_info) != const_int[k].end()){
            //             return const_int[k][first_son_info];
            //         }
            //     }
            //     WRONG;
            // }else if (std::is_same<T, float>){
            //     int k = stk_top;
            //     for (; k >= 0; k --){
            //         if (const_float[k].find(first_son_info) != const_float[k].end()){
            //             return const_float[k][first_son_info];
            //         }
            //     }
            // }
        }else if (first_son_type == "NumberAst"){
            return calc_first;
        }else WRONG;
    }

    if (cur_type == "NumberAst"){
        if (son_num != 1) WRONG;
        return calc_first;
    }

    if (cur_type == "IntConstAst"){
        return std::stoi(cur_info);
    }

    if (cur_type == "FloatConstAst"){
        return std::stof(cur_info);
    }

    return 0;
}

String str_replace(String str, String s1, String s2){
    int len1 = s1.length(), len2 = s2.length();
    for (int pos = 0; pos < str.length(); pos ++){
        if (str.substr(pos, len1) == s1){
            str = str.substr(0, pos) + s2 + str.substr(pos + len1);
            pos += 3;
        }
    }
    return str;
}

String array_IR(ObjTree::ObjManager* obj_manager, ObjTree::ObjUuid cur_node_idx){ // 使用时的IR
    // std::cout << "array_IR: " << cur_type << std::endl;
    if (son_num == 0) return "";
    String result = array_IR(obj_manager, first_son);
    result += "%" + std::to_string(var_cnt + 1) + " = getelemptr %" + std::to_string(var_cnt) + ", " + std::to_string(calc<int>(obj_manager, second_son)) + "\n";
    var_cnt ++;
    return result;
}

String left_lval(ObjTree::ObjManager* obj_manager, ObjTree::ObjUuid cur_node_idx){ // 作左值
    // std::cout << "left_lval" << std::endl;
    int k = stk_top;
    for (; k >= 0; k --){
        if (symbol_table[k].find(cur_info) != symbol_table[k].end()){
            break;
        }
    }
    if (k < 0) WRONG;
    if (obj_manager -> get_son_uuid_list(first_son).size() == 0){
        return "%" + std::to_string(++ var_cnt) + " = load @" + symbol_table[k][cur_info] + "\n";
    }else{
        String result;
        result = "%" + std::to_string(++ var_cnt) + " = @" + symbol_table[k][cur_info] + "\n";
        result += array_IR(obj_manager, first_son) + "%" + std::to_string(var_cnt + 1) + " = load %" + std::to_string(var_cnt) + "\n";
        var_cnt ++;
        return result;
    }
}

String get_param(ObjTree::ObjManager* obj_manager, ObjTree:: ObjUuid cur_node_idx, String TYPE){
    // std::cout << "get_param:" << cur_info << son_num << std::endl;
    if (son_num == 0 && cur_info == "Empty"){
        param_type = 0;
        return TYPE;
    }else if (son_num == 0 && cur_info == ""){
        param_type = 2;
        return TYPE;
    }else if (son_num == 2){
        String result = str_replace(get_param(obj_manager, first_son, TYPE), TYPE, "[" + TYPE + ", " + std::to_string(calc<int>(obj_manager, second_son)) + "]");
        param_type = param_type ? param_type : 1;
        return result;
    }else WRONG;
}

String visit_ast(ObjTree::ObjManager* obj_manager, ObjTree::ObjUuid cur_node_idx){
    const String default_output = "";
    // std::cout << cur_type << " " << cur_info << std::endl;

    if (cur_type == "CompUnitAst"){
        if (son_num == 1){
            return FIRST + "\n";
        }else if (son_num == 2){
            return FIRST + "\n" + SECOND + "\n";
        }else WRONG;
    }

    if (cur_type == "CompUnitDefAst"){
        if (son_num != 1) WRONG;
        else{
            if (first_son_type == "DeclAst"){
                return FIRST;
            } if (first_son_type == "FuncDefAst"){
                return FIRST;
            }
        }
    }

    if (cur_type == "DeclAst"){
        if (son_num != 1) WRONG;
        else{
            if (first_son_type == "ConstDeclAst"){
                return FIRST;
            }else if (first_son_type == "VarDeclAst"){
                return FIRST;
            }
        }
    }

    if (cur_type == "ConstDeclAst"){
        if (son_num != 2) WRONG;
        String first = FIRST, second = SECOND;
        return str_replace(second, "#TYPE", first);
    }

    if (cur_type == "BTypeAst"){
        if (cur_info == "KEYWORD_INT"){
            btype = 1;
            return "i32";
        }else if (cur_info == "KEYWORD_FLOAT"){
            btype = 2;
            return FLOAT;
        }
    }

    if (cur_type == "ConstDefListAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 2){
            return FIRST + SECOND;
        }else WRONG;
    }

    if (cur_type == "ConstDefAst"){ // 不支持数组常量
        if (son_num != 2) WRONG;
        symbol_table[stk_top][cur_info] = cur_info + std::to_string(block_cnt);
        if (obj_manager -> get_son_uuid_list(second_son).size() != 1) WRONG;
        if (btype == 1){
            const_int[stk_top][cur_info] = calc<int>(obj_manager, obj_manager -> get_son_uuid_list(second_son)[0]);
        }else{
            const_float[stk_top][cur_info] = calc<float>(obj_manager, obj_manager -> get_son_uuid_list(second_son)[0]);
        }
        value_type[stk_top][cur_info] = 0;
        return "";
    }

    if (cur_type == "ArrayIndexListAst"){ // 定义时的IR
        if (son_num == 0){
            return "#TYPE";
        }else if (son_num == 2){
            return str_replace(FIRST, "#TYPE", "[#TYPE, " + std::to_string(calc<int>(obj_manager, second_son)) + "]");
        }else WRONG;
    }

    if (cur_type == "InitValAst"){ // 不支持变量初始化列表
        if (cur_info == "Exp"){
            return std::to_string(calc<int>(obj_manager, first_son));
        }else if (cur_info == "InitValList"){
            return "{" + FIRST + "}";
        }else WRONG;
    }

    if (cur_type == "InitValListAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 2){
            return FIRST + ", " + SECOND;
        }else WRONG;
    }

    if (cur_type == "VarDeclAst"){
        if (son_num != 2) WRONG;
        return str_replace(SECOND, "#TYPE", FIRST);
    }

    if (cur_type == "VarDefListAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 2){
            return FIRST + SECOND;
        }else WRONG;
    }

    if (cur_type == "VarDefAst"){
        if (son_num != 1 && son_num != 2) WRONG;
        symbol_table[stk_top][cur_info] = cur_info + std::to_string(block_cnt);
        if (obj_manager -> get_son_uuid_list(first_son).size() == 0){
            value_type[stk_top][cur_info] = 0;
        }else{
            value_type[stk_top][cur_info] = 1;
        }
        String result = (stk_top == 0 ? String("global ") : String("")) + "@" + cur_info + std::to_string(block_cnt) + " = alloc " + FIRST;
        if (son_num == 2){
            result +=  ", " + SECOND;
        }
        return result + "\n";
    }

    if (cur_type == "FuncDefAst"){
        if (son_num == 2){
            return "fun @" + cur_info + "()" + FIRST \
                + " {\n" + SECOND + "}\n";
        }else if (son_num == 3){
            return "fun @" + cur_info + "(" + SECOND + ")" + FIRST \
                + " {\n" + THIRD + "}\n";
        }else WRONG;
    }

    if (cur_type == "FuncTypeAst"){
        if (cur_info == "void"){
            return "";
        }else if (cur_info.substr(0, 3) == "int"){
            return ": i32";
        }else if (cur_info.substr(0, 5) == "float"){
            return ": " + FLOAT;
        }
    }

    if (cur_type == "FuncFParamsAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 2){
            return FIRST + ", " + SECOND;
        }else WRONG;
    }

    if (cur_type == "FuncFParamAst"){
        if (son_num == 2){
            symbol_table[stk_top][cur_info] = cur_info + std::to_string(stk_top);
            String result = "@" + cur_info + std::to_string(stk_top) + ": ";
            param_type = 0;
            String tmp = get_param(obj_manager, second_son, FIRST);
            result += (param_type == 2 ? "*" : "") + tmp;
            value_type[stk_top][cur_info] = param_type;
            return result;
        }else WRONG;
    }

    if (cur_type == "BlockAst"){
        if (son_num == 1){
            stk_top ++;
            String result = "%block_entry" + std::to_string(++ block_cnt) + ":\n" + FIRST;
            result += "jump %block_entry" + std::to_string(++ block_cnt) + "\n\n";
            result += "%block_entry" + std::to_string(block_cnt) + ":\n";
            symbol_table[stk_top --].clear();
            return result;
        }else WRONG;
    }

    if (cur_type == "BlockItemListAst"){
        if (son_num == 0){
            return "";
        }else if (son_num == 2){
            return FIRST + "\n" + SECOND;
        }else WRONG;
    }

    if (cur_type == "BlockItemAst"){
        if (son_num != 1) WRONG;
        if (first_son_type == "DeclAst"){
            return FIRST;
        }else if (first_son_type == "StmtAst"){
            return FIRST;
        }else WRONG;
    }

    if (cur_type == "StmtAst"){
        if (son_num == 2 && obj_manager -> get_type(first_son) == "LValAst"){
            String result = SECOND;
            int tmp = var_cnt;
            result += left_lval(obj_manager, first_son);
            return result + "store %" + std::to_string(tmp) + ", %" + std::to_string(var_cnt) + "\n";
        }else if (son_num == 0 && cur_info == ""){
            return "";
        }else if (son_num == 1 && cur_info == "" && first_son_type == "ExpAst"){
            return "";
        }else if (son_num == 1 && cur_info == "" && first_son_type == "BlockAst"){
            return FIRST;
        }else if (son_num == 2 && cur_info == "If"){ // 未实现短路求值
            int tmp;
            String result = "%if_entry" + std::to_string(++ block_cnt) + ":\n" + FIRST;
            result += "br %" + std::to_string(var_cnt) + ", %if_body" + std::to_string(++ block_cnt);
            result += ", %if_end" + std::to_string(tmp = ++ block_cnt) + "\n\n";
            result += "%if_body" + std::to_string(tmp - 1) + ":\n" + SECOND;
            result += "jump %if_end" + std::to_string(tmp) + "\n\n";
            result += "%if_end" + std::to_string(tmp) + ":\n";
            return result;
        }else if (son_num == 3 && cur_info == "IfElse"){
            int tmp1, tmp2;
            String result = "%if_entry" + std::to_string(++ block_cnt) + ":\n" + FIRST;
            result += "br %" + std::to_string(var_cnt) + ", %if_body" + std::to_string(++ block_cnt);
            result += ", %else_body" + std::to_string(tmp1 = ++ block_cnt) + "\n\n";
            result += "%if_body" + std::to_string(tmp1 - 1) + ":\n" + SECOND;
            result += "jump %if_end" + std::to_string(tmp2 = ++ block_cnt) + "\n\n";
            result += "%else_body" + std::to_string(tmp1) + ":\n" + THIRD;
            result += "jump %if_end" + std::to_string(tmp2) + "\n\n";
            result += "%if_end" + std::to_string(tmp2) + ":\n";
            return result;
        }else if (son_num == 2 && cur_info == "While"){
            int tmp1, tmp2;
            String result = "%while_entry" + std::to_string(now_entry = tmp1 = ++ block_cnt) + ":\n" + FIRST;
            result +=  "br %" + std::to_string(var_cnt) + ", %while_body" + std::to_string(++ block_cnt);
            result += ", %while_end" + std::to_string(now_end = tmp2 = ++ block_cnt) + "\n\n";
            result +=  "%while_body" + std::to_string(tmp2 - 1) + ":\n" + SECOND;
            result +=  "jump %while_entry" + std::to_string(tmp1) + "\n\n";
            result +=  "%while_end" + std::to_string(tmp2) + ":\n";
            return result;
        }else if (son_num == 0 && cur_info == "Break"){
            return "jump %while_end" + std::to_string(now_end) + "\n";
        }else if (son_num == 0 && cur_info == "Continue"){
            return "jump %while_entry" + std::to_string(now_entry) + "\n";
        }else if (son_num == 0 && cur_info == "Return"){
            return "ret\n";
        }else if (son_num == 1 && cur_info == "ReturnExp"){
            return FIRST + "ret %" + std::to_string(var_cnt) + "\n";
        }else WRONG;
    }

    if (cur_type == "IntConstAst"){
        if (son_num == 0){
            return cur_info;
        }else WRONG;
    }

    if (cur_type == "FloatConstAst"){
        if (son_num == 0){
            return cur_info;
        }else WRONG;
    }

    if (cur_type == "ExpAst"){
        if (son_num == 1){
            return FIRST;
        }else WRONG;
    }

    if (cur_type == "CondAst"){
        if (son_num == 1){
            return FIRST;
        }else WRONG;
    }

    if (cur_type == "LValAst"){ // 作右值
        int k = stk_top;
        for (; k >= 0; k --){
            if (symbol_table[k].find(cur_info) != symbol_table[k].end()){
                break;
            }
        }
        if (k < 0) WRONG;
        if (const_int[k].find(cur_info) != const_int[k].end()){
            return "li %" + std::to_string(++ var_cnt) + ", " + std::to_string(const_int[k][cur_info]) + "\n";
        }
        if (const_float[k].find(cur_info) != const_float[k].end()){ // 未约定，暂且认为是flw
            return "flw %" + std::to_string(++ var_cnt) + ", " + std::to_string(const_float[k][cur_info]) + "\n";
        }
        return left_lval(obj_manager, cur_node_idx);
    }

    if (cur_type == "PrimaryExpAst"){
        if (son_num != 1) WRONG;
        if (first_son_type == "ExpAst"){
            return FIRST;
        }else if (first_son_type == "LValAst"){
            return FIRST;
        }else if (first_son_type == "NumberAst"){
            return FIRST;
        }
    }

    if (cur_type == "NumberAst"){
        if (son_num != 1) WRONG;
        if (first_son_type == "IntConstAst"){
            return "li %" + std::to_string(++ var_cnt) + ", " + FIRST + "\n";
        }else if (first_son_type == "FloatConstAst"){  // 暂且认为加载浮点立即数的命令是flw
            return "flw %" + std::to_string(++ var_cnt) + ", " + FIRST + "\n";
        }
    }

    if (cur_type == "UnaryExpAst"){
        if (son_num == 1 && cur_info == ""){
            return FIRST;
        }else if (son_num == 0){
            return "%" + std::to_string(++ var_cnt) + " = call @" + cur_info + "()\n";
        }else if (son_num == 1 && cur_info != ""){
            call_params.clear();
            String result = FIRST + "%" + std::to_string(++ var_cnt) + " = call @" + cur_info + "(";
            for (int i = 0; i < call_params.size(); i ++)
                result += (i > 0 ? "," : "") + call_params[i];
            return result + ")\n";
        }else if (son_num == 2){
           return SECOND + FIRST;
        }
    }

    if (cur_type == "UnaryOpAst"){
        if (cur_info == "+"){
            return "";
        }else if (cur_info == "-"){
            String result = "%" + std::to_string(++ var_cnt);
            return result + " = sub 0, %" + std::to_string(var_cnt - 1) + "\n";
        }else if (cur_info == "!"){
            String result = "%" + std::to_string(++ var_cnt);
            return result + " = xor -1, %" + std::to_string(var_cnt - 1) + "\n";
        }else WRONG;
    }

    if (cur_type == "FuncRPAREmsAst"){
        if (son_num == 1){
            String result = FIRST;
            call_params.push_back("%" + std::to_string(var_cnt));
            return result;
        }else{
            String result = FIRST + SECOND;
            call_params.push_back("%" + std::to_string(var_cnt));
            return result;
        }
    }

    if (cur_type == "MulExpAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 3){
            String result = FIRST;
            int num1 = var_cnt;
            result += THIRD;
            int num2 = var_cnt;
            String Op = second_son_info;
            if (Op == "*"){
                return result + "%" + std::to_string(++ var_cnt) + " = mul %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == "/"){
                return result + "%" + std::to_string(++ var_cnt) + " = div %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == "%"){
                return result + "%" + std::to_string(++ var_cnt) + " = mod %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "AddExpAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 3){
            String result = FIRST;
            int num1 = var_cnt;
            result += THIRD;
            int num2 = var_cnt;
            String Op = second_son_info;
            if (Op == "+"){
                return result + "%" + std::to_string(++ var_cnt) + " = add %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == "-"){
                return result + "%" + std::to_string(++ var_cnt) + " = sub %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "RelExpAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 3){
            String result = FIRST;
            int num1 = var_cnt;
            result += THIRD;
            int num2 = var_cnt;
            String Op = second_son_info;
            if (Op == "<"){
                return result + "%" + std::to_string(++ var_cnt) + " = lt %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == "<="){
                return result + "%" + std::to_string(++ var_cnt) + " = le %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == ">"){
                return result + "%" + std::to_string(++ var_cnt) + " = gt %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == ">="){
                return result + "%" + std::to_string(++ var_cnt) + " = ge %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "EqExpAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 3){
            String result = FIRST;
            int num1 = var_cnt;
            result += THIRD;
            int num2 = var_cnt;
            String Op = second_son_info;
            if (Op == "=="){
                return result + "%" + std::to_string(++ var_cnt) + " = eq %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else if (Op == "!="){
                return result + "%" + std::to_string(++ var_cnt) + " = ne %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
            }else WRONG;
        }else WRONG;
    }

    if (cur_type == "LAndExpAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 2){
            String result = FIRST;
            int num1 = var_cnt;
            result += SECOND;
            int num2 = var_cnt;
            return result + "%" + std::to_string(++ var_cnt) + " = and %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
        }else WRONG;
    }

    if (cur_type == "LOrExpAst"){
        if (son_num == 1){
            return FIRST;
        }else if (son_num == 2){
            String result = FIRST;
            int num1 = var_cnt;
            result += SECOND;
            int num2 = var_cnt;
            return result + "%" + std::to_string(++ var_cnt) + " = or %" + std::to_string(num1) + ", %" + std::to_string(num2) + "\n";
        }else WRONG;
    }

    // and, or, xor, shl, shr, sar.

    return default_output;
}

bool is_block(String str){
    return str.substr(0, 3) == "%if" || str.substr(0, 5) == "%else" || str.substr(0, 6) == "%while" || str.substr(0, 6) == "%block";
}

bool is_jump(String str){
    return str.substr(0, 4) == "jump" || str.substr(0, 2) == "br" || str.substr(0, 3) == "ret";
}

String scan(String IR){ // 处理(%if_end|%while_end|%block_entry)相连的情况
    String new_IR = "";
    std::stringstream ss(IR);
    std::vector<String> lines;
    String line;
    while (std::getline(ss, line, '\n')) {
        if (line != "") lines.push_back(line);
    }
    for (int i = 0; i < lines.size() - 1; i ++){
        if (is_block(lines[i + 1]) && !is_jump(lines[i]) && lines[i].substr(0, 3) != "fun")
            lines.insert(lines.begin() + i + 1, "jump " + lines[i + 1].substr(0, lines[i + 1].length() - 1));
        if (is_jump(lines[i]) && is_jump(lines[i + 1])){
            lines.erase(lines.begin() + i + 1);
            i --;
            continue;
        }
        if (is_block(lines[i]) && lines[i + 1] == "}") continue;
        if (is_block(lines[i])) new_IR += "\n";
        new_IR += lines[i] + "\n";
        if (lines[i] == "}") new_IR += "\n";
    }
    return new_IR + lines[lines.size() - 1] + "\n";
}

void generate_ir(ObjTree::ObjManager* obj_manager, const String& output_ir_file) {
    // die_if_error(false, make_error_message("unimplemented"));

    // std::cout << "-----------------------------" << std::endl;
    String IR = visit_ast(obj_manager, obj_manager -> get_last_uuid());
    std::ofstream output_file(output_ir_file);
    IR = scan(IR);
    output_file << IR;
    output_file.close();
    // std::cout << "-----------------------------" << std::endl;

}

} // namespace MiddleEnd;
