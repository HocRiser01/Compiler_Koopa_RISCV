#pragma once

#include <string>
#include "../ObjTree/ObjManager.h"

typedef std::string String;

namespace BackEnd {

void output_code(const String& input_ir_file, const String& output_asm_file);

} // namespace BackEnd
