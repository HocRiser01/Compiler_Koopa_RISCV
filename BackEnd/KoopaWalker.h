//
// Created by yyi on 2023/6/12.
//

#ifndef COMPILER_KOOPAWALKER_H
#define COMPILER_KOOPAWALKER_H

#include <sstream>
#include <cstdio>
#include <string>
#include <algorithm>

#include "RegisterAllocator.h"

std::string Visit(const koopa_raw_program_t &program);
void Visit(const koopa_raw_function_t &func);
void Visit(const koopa_raw_basic_block_t &bb);
void Visit(const koopa_raw_value_t &val);
void Visit(const koopa_raw_slice_t &slice);
#endif //COMPILER_KOOPAWALKER_H
