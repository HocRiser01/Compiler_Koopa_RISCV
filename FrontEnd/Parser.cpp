#include "Parser.h"

// 链接 YACC 的解析函数
extern ObjTree::ObjUuid yacc_lex_get_ast(ObjTree::ObjManager*, String);

ObjTree::ObjUuid FrontEnd::parse_from_file(ObjTree::ObjManager* obj_manager, String filename) {
    return yacc_lex_get_ast(obj_manager, filename);
}
