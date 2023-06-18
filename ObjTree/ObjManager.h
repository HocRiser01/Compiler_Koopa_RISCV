#pragma once

#include <string>
#include <vector>

#include "../ErrorMessage.h"

namespace ObjTree {

typedef std::string          String;
typedef long long            ObjUuid;
typedef std::vector<ObjUuid> ObjUuidList;

struct NodeInfo { // 结点信息
    ObjUuid     uuid;
    ObjUuidList son_uuid_list;
    String      type_name;
    String      node_info;
};

typedef std::vector<NodeInfo> NodeInfoList;

class ObjManager { // 使用统一的对象管理器管理所有的对象
public:
    ObjManager() {
        last_uuid = 0;
        add_empty_node(); // node 0 is node used
    }
    virtual ~ObjManager() {
    }

    // 禁止使用拷贝和复制函数
    ObjManager            (const ObjManager&) = delete;
    ObjManager& operator= (const ObjManager&) = delete;

    // 获得最后一次分配的 UUID
    ObjUuid get_last_uuid() const {
        return last_uuid;
    }

    // 申请一个从来都没出现过的 UUID, (所有 UUID > 0)
    // 这里没有使用真正的 UUID 主要是为了方便实现
    ObjUuid get_uuid() {
        ObjUuid uuid_now = ++ last_uuid;
        add_empty_node();
        node_info_list[uuid_now].uuid = uuid_now;
        return uuid_now;
    }

    // 检查一个 uuid 是否被分配过
    bool check_available(ObjUuid uuid) const {
        return 0 < uuid && uuid <= last_uuid;
    }

    // 设置/获取结点类型
    void set_type(ObjUuid uuid, String type_name) {
        die_if_error(check_available(uuid), make_error_message("uuid not defined"));
        node_info_list[uuid].type_name = type_name;
    }
    String get_type(ObjUuid uuid) const {
        die_if_error(check_available(uuid), make_error_message("uuid not defined"));
        return node_info_list[uuid].type_name;
    }

    // 设置/获取结点信息
    void set_info(ObjUuid uuid, String node_info) {
        die_if_error(check_available(uuid), make_error_message("uuid not defined"));
        node_info_list[uuid].node_info = node_info;
    }
    String get_info(ObjUuid uuid) const {
        die_if_error(check_available(uuid), make_error_message("uuid not defined"));
        return node_info_list[uuid].node_info;
    }

    // 为某个结点设置自结点集合
    void add_son(ObjUuid father_uuid, const ObjUuidList& uuid_list) {
        die_if_error(check_available(father_uuid), make_error_message("father_uuid not defined"));
        node_info_list[father_uuid].son_uuid_list = uuid_list;
    }

    // 得到子结点序列
    const ObjUuidList& get_son_uuid_list(ObjUuid uuid) const {
        die_if_error(check_available(uuid), make_error_message("uuid not defined"));
        return node_info_list[uuid].son_uuid_list;
    }

    // 此功能主要用来测试树形结构的正确性
    String get_node_info_string(ObjUuid uuid) const {
        die_if_error(check_available(uuid), make_error_message("uuid not defined"));
        String ans = std::to_string(uuid) + "(" + get_type(uuid) + ")" + "[" + get_info(uuid) + "]" + "{";
        bool first = true;
        for(auto son_uuid: get_son_uuid_list(uuid)) {
            if(first) {
                first = false;
            }else {
                ans += ",";
            }
            ans += get_node_info_string(son_uuid);
        }
        ans += "}";
        return ans;
    }

private:

    void add_empty_node() { // 添加空结点
        node_info_list.push_back((NodeInfo){});
    }

    ObjUuid      last_uuid;
    NodeInfoList node_info_list;
};

} // namespace ObjTree;
