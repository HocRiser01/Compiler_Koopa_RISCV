#include <iostream>

#include "ObjManager.h"
#include "../ErrorMessage.h"

using namespace ObjTree;

static void test_case_001() {
    ObjManager obj_manager;

    ObjUuid a = obj_manager.get_uuid();
    obj_manager.set_info(a, "A");
    obj_manager.set_type(a, "AstNode1");

    ObjUuid b = obj_manager.get_uuid();
    obj_manager.set_info(b, "B");
    obj_manager.set_type(b, "AstNode2");

    ObjUuid c = obj_manager.get_uuid();
    obj_manager.set_info(c, "C");
    obj_manager.set_type(c, "AstNode3");

    // A -> {B, C}
    obj_manager.add_son(a, {b, c});

    bool check_result = (obj_manager.get_node_info_string(a) == "1(AstNode1)[A]{2(AstNode2)[B]{},3(AstNode3)[C]{}}");
    std::cout << make_test_report(check_result);
}

static void test_case_002() {
    ObjManager obj_manager;

    ObjUuid a = obj_manager.get_uuid();
    obj_manager.set_info(a, "A");
    obj_manager.set_type(a, "AstNodeA");

    ObjUuid b = obj_manager.get_uuid();
    obj_manager.set_info(b, "B");
    obj_manager.set_type(b, "AstNodeB");

    ObjUuid c = obj_manager.get_uuid();
    obj_manager.set_info(c, "C");
    obj_manager.set_type(c, "AstNodeC");

    // A -> B -> C
    obj_manager.add_son(a, {b});
    obj_manager.add_son(b, {c});

    bool check_result = (obj_manager.get_node_info_string(a) == "1(AstNodeA)[A]{2(AstNodeB)[B]{3(AstNodeC)[C]{}}}");
    std::cout << make_test_report(check_result);
}

static void test_obj_utils() {
    test_case_001();
    test_case_002();
}

#ifdef TEST_OBJ_UTILS

int main() {
    test_obj_utils();
}

#endif
