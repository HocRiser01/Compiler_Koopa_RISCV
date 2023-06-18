#include <string>
#include <map>

#include "StrDump.h"

typedef std::string              String;
typedef std::map<String, String> DictString;


DictString global_dict_string;

// 缓存并合并相同字符串
const char* merged_str_dump(const char* str) {
    String tmp_str = str;
    if(global_dict_string.count(tmp_str) == 0) { // 如果当前没缓存过，就缓存一个
        global_dict_string[tmp_str] = tmp_str;
    }
    return global_dict_string[tmp_str].c_str();
}
