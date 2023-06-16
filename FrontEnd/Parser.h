#pragma once

#include <string>
#include "../ObjTree/ObjManager.h"

typedef std::string String;

namespace FrontEnd {

// 读入文件内容，并解析为抽象语法树
ObjTree::ObjUuid parse_from_file(ObjTree::ObjManager* obj_manager, String filename);

} // namespace FrontEnd;
