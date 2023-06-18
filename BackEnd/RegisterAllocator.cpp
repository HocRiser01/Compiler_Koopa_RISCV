// register_allocator.cpp

#include "RegisterAllocator.h"

RegisterAllocator::RegisterAllocator() {
    for (int i = 0; i < 6; ++i) {
        available_registers_.insert("t" + std::to_string(i));
    }
//    for (int i = 0; i < 6; i ++ ) {
//        available_registers_.insert("a" + std::to_string(i));
//    }
}

std::string RegisterAllocator::Allocate() {
    if (available_registers_.empty()) {
        throw std::runtime_error("Out of registers!");
    }

    std::string reg = *available_registers_.begin();
    available_registers_.erase(available_registers_.begin());
    return reg;
}

void RegisterAllocator::Set(ull name, std::string reg) {
    name_register[name] = reg;
    return;
}

std::string RegisterAllocator::Get(std::string name) {
    return Get((ull)std::stoi(name));
}

std::string RegisterAllocator::Get(ull name) {
    if (name_register.count(name) <= 0) {
        return "NULL";
    }
    return name_register[name];
}

void RegisterAllocator::Deallocate(const std::string &reg) {
    if (available_registers_.count(reg) == 0)
        available_registers_.insert(reg);
}
