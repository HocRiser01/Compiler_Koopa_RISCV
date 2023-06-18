#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../../ErrorMessage.h"

typedef std::string      String;
typedef std::vector<int> IntList;

namespace MiddleEnd {

// 类型信息
struct TypeInfo {
    String  base_type;      // 只能是 "int", "float", "void"
    String  construct_type; // 只能是 "array", "pointer", "none"
    IntList index_info;     // 记录每一维下标的长度，指针变量第一维度下标长度记为零

    void sanity_check() const;           // 类型信息合法性检查
    String get_type_info_string() const; // 类型信息序列化：用于测试
};

typedef std::vector<TypeInfo> TypeInfoList;

struct VariableInfo {
    int      local_offset;  // 全局变量在全局变量区的偏移量，局部变量在局部变量区的偏移量
    TypeInfo variable_type; // 变量类型
};

// 由于 local_offset >= 0, 使用小于零的 local_offset 表示变量信息不存在
const VariableInfo VARIABLE_INFO_NOT_FOUND = {-1, {}};

// 局部化区中的变量名信息
struct LocalScope {
    std::map<String, VariableInfo> name_to_info;

    bool variable_exist(String variable_name);                    // 检查变量名是否存在于当前局部化区
    VariableInfo get_variable_info_by_name(String variable_name); // 根据变量名查询变量信息
};

typedef std::vector<LocalScope> LocalScopeList;

// 函数的相关信息
struct FunctionInfo {
    String         func_name;           // 函数名
    int            local_variable_size; // 当前时刻，局部变量占据的总空间大小
    int            temp_variable_size ; // 当前时刻，临时变量占据的总空间大小
    TypeInfo       return_type   ;      // 返回值类型
    TypeInfoList   arguments_type;      // 参数类型
    LocalScopeList local_scope_list;    // 局部化区信息列表，一个函数至少有一个局部化区，参数视为初始局部化区中的元素

    // 找到局部变量信息
    VariableInfo get_variable_info_by_name(String variable_name) {
        // 从后向前枚举所有局部化区信息
        for(int i = (int)local_scope_list.size() - 1; i >= 0; i -= 1) {
            auto& local_scope = local_scope_list[i];
            if(local_scope.variable_exist(variable_name)) {
                return local_scope.get_variable_info_by_name(variable_name);
            }
        }
        return VARIABLE_INFO_NOT_FOUND;
    }

    int alloc_local(int length) { // 申请一块局部变量空间，返回首偏移量
        int pos = local_variable_size;
        local_variable_size += length;
        return pos;
    }

    int alloc_temp(int length) { // 申请一块临时变量空间，返回首偏移量
        int pos = temp_variable_size;
        temp_variable_size += length;
        return pos;
    }
};

// 函数注册表
// 记录从 函数名 到 函数信息 的映射
// 函数信息包括：
//   返回值类型，参数个数与类型，（参数属于局部变量）局部变量所占空间大小，临时变量所占空间大小
class FunctionRegisterTable {
public:
    FunctionRegisterTable() {
        init_system_lib_function(); // 初始化系统提供的库函数信息
    }
    virtual ~FunctionRegisterTable() {}

private:
    void init_system_lib_function();

    std::map<String, std::unique_ptr<FunctionInfo>> function_info_map;
};

} // namespace MiddleEnd;
