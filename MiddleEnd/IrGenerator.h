#pragma once

#include <string>
#include "../ObjTree/ObjManager.h"

typedef std::string String;

namespace MiddleEnd {

// 中间代码生成：根据抽象语法树，生成中间代码对应的树形结构
void generate_ir(ObjTree::ObjManager* obj_manager, const String& output_ir_file);

// 遍历AST，产生Koopa IR

String visit_ast(ObjTree::ObjManager* obj_manager, ObjTree::ObjUuid cur_node_idx);

} // namespace MiddleEnd;
