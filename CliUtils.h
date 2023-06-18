#pragma once

#include <string>
#include <vector>

// 类型定义
typedef std::string         String;
typedef std::vector<String> StringList;

namespace CliUtils {

// 将命令行输入的参数解析成字符串数组
inline StringList parse_vector_string(int argc, const char **argv) {
	StringList string_list;
	for(int i = 1; i < argc; i += 1) {
		string_list.push_back(argv[i]);
	}
	return string_list;
}

// 检查命令行参数中 -o 的下一个字符串
// 如果没找到 -o 或者 -o 后没有字符串则返回空字符串
// 如果 -o 出现了多次，以第一次出现为准
inline String get_output_file(const StringList& string_list) {
	String ans = "";
	bool next_enable = false;
	for(const auto& str: string_list) {
		if(next_enable) { // 说明上一个字符串是 -o
			ans = str;
			break;
		}
		if(str == "-o") {
			next_enable = true;
		}
	}
	return ans;
}

// 获取输入文件名
// 输入文件名要求不以 “-” 开头
// 跳过 -o 的下一个字符串
// 有多个符合条件的文件名以第一个为准
// 没有符合条件的文件名返回空字符串
inline String get_input_file(const StringList& string_list) {
	String ans = "";
	bool skip_next = false;
	for(const auto& str: string_list) {
		if(str == "-o") {
			skip_next = true;
		}else {
			if(skip_next) {
				skip_next = false;
			}else {
				if(str[0] != '-') { // 找到了对应的字符串
					ans = str;
					break;
				}
			}

		}
	}
	return ans;
}

// 寻找 -O2 优化开关
inline bool get_optimize_option(const StringList& ops) {
	for(const auto& str: ops) {
		if(str == "-O2") { // found
			return true;
		}
	}
	return false;
}

} // namespace CliUtils;
