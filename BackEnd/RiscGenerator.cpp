//
// Created by yyi on 2023/6/12.
//
//#include <koopa.h>

#include <fstream>

#include "koopa.h"
#include "KoopaWalker.h"
#include "RiscGenerator.h"
#include "../ErrorMessage.h"

void BackEnd::output_code(const String& input_ir_file, const String& output_asm_file) {
    // 读入字符形式的 Koopa IR 文件

    koopa_program_t program;
    koopa_error_code_t  ret = koopa_parse_from_file(input_ir_file.c_str(), &program);

    // 检查读入是否出错
    die_if_error(ret == 0, make_error_message("koopa parse file error"));
    //解析为 raw program
    koopa_raw_program_builder_t  builder = koopa_new_raw_program_builder();
    koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
    //回收
    koopa_delete_program(program);

    String res = Visit(raw);

    std::ofstream outfile(output_asm_file);

    outfile << res;
    outfile.close();

    //回收 builder 内存
    koopa_delete_raw_program_builder(builder);
}
