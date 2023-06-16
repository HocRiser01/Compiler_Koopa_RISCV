// encoding: utf-8

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "CliUtils.h"              // 命令行输入的解析模块
#include "ErrorMessage.h"          // 构造错误信息
#include "FrontEnd/Parser.h"       // 编译器前端：负责读入文件并生成抽象语法树
#include "ObjTree/ObjManager.h"    // 对象管理器模块，用于管理抽象语法树结点与中间代码结点
#include "MiddleEnd/IrGenerator.h" // 中间代码生成器
#include "BackEnd/ArmGenerator.h"  // 生成 ARM 目标代码

static ObjTree::ObjUuid get_random_uuid() {
	ObjTree::ObjUuid r1 = ((ObjTree::ObjUuid)rand());
	ObjTree::ObjUuid r2 = ((ObjTree::ObjUuid)rand());
	ObjTree::ObjUuid r3 = ((ObjTree::ObjUuid)rand());
	ObjTree::ObjUuid r4 = ((ObjTree::ObjUuid)rand());
	return (((((r1 << 15) | r2) << 15) | r3) << 15) | r4; // gen random integer
}

int main(int argc, const char** argv) {
	srand(time(NULL)); // 重置随机数种子

	StringList ops         = CliUtils::parse_vector_string(argc, argv);
	String     output_file = CliUtils::get_output_file    (ops);
	String     input_file  = CliUtils::get_input_file     (ops);
	bool       optimize_on = CliUtils::get_optimize_option(ops);

	// 实例化对象管理器
	std::unique_ptr<ObjTree::ObjManager> obj_manager(new ObjTree::ObjManager());

	// 生成抽象语法树
	ObjTree::ObjUuid ast_root_uuid = FrontEnd::parse_from_file(obj_manager.get(), input_file);

	// 使用 .koopa 文件存储一个临时的中间代码
	String ir_file_name = input_file + ".koopa";

	// 生成中间代码：将中间代码输出到文件
	MiddleEnd::generate_ir(obj_manager.get(), ir_file_name);

	// 目标代码生成
	BackEnd::output_code(ir_file_name, output_file);
	return 0;
}
