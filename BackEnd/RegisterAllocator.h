//
// Created by yyi on 2023/6/13.
//

#ifndef COMPILER2022_X_REGISTERALLOCATOR_H
#define COMPILER2022_X_REGISTERALLOCATOR_H

// register_allocator.h

#include <string>
#include <set>
#include <unordered_map>
#include <cstdint>
#include <stdexcept>

#define ull unsigned long long
class RegisterAllocator {
public:
    uint8_t cnt;
    RegisterAllocator();
    std::string Allocate();
    void Set(ull name, std::string reg);
    std::string Get(std::string name);
    std::string Get(ull name);
    void Deallocate(const std::string &reg);

private:
    std::set<std::string> available_registers_;
    std::unordered_map<ull, std::string> name_register;
};


#endif //COMPILER2022_X_REGISTERALLOCATOR_H
