#include "../ErrorMessage.h"
#include "ArmGenerator.h"

// for test only
static String test_arm_code_a4c0398c_3a74_4d8c_9d52_8acf1febb075 = "\
    .arch armv7ve\n\
    .arm\n\
    .global main\n\
    .section .text\n\
main:\n\
    push {lr}\n\
    mov r0,#3\n\
    pop {pc}\n\
";

void BackEnd::output_code(const String& input_ir_file, const String& output_asm_file) {
    // ...
    // die_if_error(false, make_error_message("please add output_code function here"));
}
