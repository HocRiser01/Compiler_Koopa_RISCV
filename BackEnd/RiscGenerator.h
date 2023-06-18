//
// Created by yyi on 2023/6/12.
//

#ifndef COMPILER_RISCGENERATOR_H
#define COMPILER_RISCGENERATOR_H
#include <string>

typedef std::string String;

namespace BackEnd {
    void output_code(const String& input_ir_file, const String& output_asm_file);
}
#endif //COMPILER_RISCGENERATOR_H