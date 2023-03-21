#include <cassert>
#include <ranges>
#include <iomanip>
#include "Registry.h"

Register::register_value &
Register::getRegisterReference(user_regs_struct &regsStruct, Register::Identifier registerName) {
    switch (registerName) {
        case Register::Identifier::rax:
            return regsStruct.rax;
        case Register::Identifier::rbx:
            return regsStruct.rbx;
        case Register::Identifier::rcx:
            return regsStruct.rcx;
        case Register::Identifier::rdx:
            return regsStruct.rdx;
        case Register::Identifier::rdi:
            return regsStruct.rdi;
        case Register::Identifier::rsi:
            return regsStruct.rsi;
        case Register::Identifier::rbp:
            return regsStruct.rbp;
        case Register::Identifier::rsp:
            return regsStruct.rsp;
        case Register::Identifier::r8:
            return regsStruct.r8;
        case Register::Identifier::r9:
            return regsStruct.r9;
        case Register::Identifier::r10:
            return regsStruct.r10;
        case Register::Identifier::r11:
            return regsStruct.r11;
        case Register::Identifier::r12:
            return regsStruct.r12;
        case Register::Identifier::r13:
            return regsStruct.r13;
        case Register::Identifier::r14:
            return regsStruct.r14;
        case Register::Identifier::r15:
            return regsStruct.r15;
        case Register::Identifier::rip:
            return regsStruct.rip;
        case Register::Identifier::eflags:
            return regsStruct.eflags;
        case Register::Identifier::cs:
            return regsStruct.cs;
        case Register::Identifier::orig_rax:
            return regsStruct.orig_rax;
        case Register::Identifier::fs_base:
            return regsStruct.fs_base;
        case Register::Identifier::gs_base:
            return regsStruct.gs_base;
        case Register::Identifier::fs:
            return regsStruct.fs;
        case Register::Identifier::gs:
            return regsStruct.gs;
        case Register::Identifier::ss:
            return regsStruct.ss;
        case Register::Identifier::ds:
            return regsStruct.ds;
        case Register::Identifier::es:
            return regsStruct.es;
        default:
            assert(false && "Invalid register identifier");
    }
}

std::string_view Register::registerNameToString(const Register::Identifier &reg) {
    auto info = std::ranges::find(Register::ALL_REGISTERS, reg, &Register::RegisterInfo::identifier);
#ifdef DEBUG
    if (info == std::ranges::end(Register::ALL_REGISTERS)) {
        throw std::runtime_error("Unknown register");
    }
#endif
    return info->shortName;
}


std::ostream &operator<<(std::ostream &os, const Register::Identifier &registryName) {
    return os << std::setfill(' ') << std::setw(Register::MAX_REGISTRY_NAME_LENGTH)
              << Register::registerNameToString(registryName);
}


