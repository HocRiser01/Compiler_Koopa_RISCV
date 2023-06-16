#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

#include "../../../ObjTree/ObjManager.h"

using namespace std;

extern FILE *yyin;
extern int yyparse(ObjTree::ObjManager* obj_manager);

typedef std::string String;

ObjTree::ObjUuid yacc_lex_get_ast(ObjTree::ObjManager* obj_manager, String input_file) {
    // read input file
    yyin = fopen(input_file.c_str(), "r");
    die_if_error(yyin, make_error_message("can not open input_file"));

    // scan and parse input file into AST
    auto ret = yyparse(obj_manager);
    die_if_error(!ret, make_error_message("yyparse failed"));

    return obj_manager->get_last_uuid();
}

#ifdef TEST_YACC_LEX

int main() {
    std::unique_ptr<ObjTree::ObjManager> obj_manager(new ObjTree::ObjManager());
    ObjTree::ObjUuid ans = yacc_lex_get_ast(obj_manager.get(), "test.sy");
    std::cout << obj_manager->get_node_info_string(ans) << std::endl;
    return 0;
}

#endif
