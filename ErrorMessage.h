#pragma once

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

typedef std::string String;

// 构造错误信息字符串
// 信息的总长度不要太长，超过 2047 字节可能会导致数组越界
#define make_error_message(const_char_ptr_msg) make_error_message_raw(__FILE__, __FUNCTION__, __LINE__, (const_char_ptr_msg))

static String make_error_message_raw(String file, String function, int line, String const_char_ptr_msg) {
    String ans = "";
    ans += file;
    ans +=  ":\n|\n|----";
    ans += function;
    ans += " (line ";
    ans += std::to_string(line);
    ans +=  "): \n     |\n     |---- error: ";
    ans += const_char_ptr_msg;
    ans += "\n";
    return ans;
}

// 构造测试输出字符串
// 总长度限制同上
#define make_test_report(check_result) make_test_report_raw(__FILE__, __FUNCTION__, __LINE__, (check_result))

static String make_test_report_raw(String file, String function, int line, int check_result) {
    String ans = "";
    ans += file;
    ans += ": ";
    ans +=  function;
    ans += ": ";
    ans += (check_result ? "AC" : "WA");
    ans += "\n";
    return ans;
}

// 检查条件是否为真
// 如果条件为假，输出错误信息并结束程序
#define die_if_error_raw_2968d81b_6167_414b_bbff_0385c65312a0(condition_true, output_message) \
     (condition_true ? 0 : (\
        std::cerr << output_message,\
        exit(1), 1\
    ))

// 我发现我总是忘了写 make_error_message
// 所以就再封装一下吧
#define die_if_error(condition_true, output_message) \
    die_if_error_raw_2968d81b_6167_414b_bbff_0385c65312a0(condition_true, (output_message))

// show unimplemented message
#define show_unimplemented_message() \
    (std::cerr << make_error_message("unimplemented"))
