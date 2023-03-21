
#ifndef SIMPLE_DEBUGGER_REGISTRY_H
#define SIMPLE_DEBUGGER_REGISTRY_H


#include <sys/user.h>
#include <string_view>

namespace Register {
    using register_value = decltype(user_regs_struct::rax);
    constexpr size_t MAX_REGISTRY_NAME_LENGTH = 8;

    enum class Identifier {
        rax, rbx, rcx, rdx,
        rdi, rsi, rbp, rsp,
        r8, r9, r10, r11,
        r12, r13, r14, r15,
        rip, eflags, cs,
        orig_rax, fs_base,
        gs_base,
        fs, gs, ss, ds, es
    };

    struct RegisterInfo {
        Identifier identifier;
        std::string_view description;
        std::string_view shortName;
    };

    constexpr RegisterInfo ALL_REGISTERS[] = {
            {Identifier::rax,      "rax",      "rax"},
            {Identifier::rbx,      "rbx",      "rbx"},
            {Identifier::rcx,      "rcx",      "rcx"},
            {Identifier::rdx,      "rdx",      "rdx"},
            {Identifier::rdi,      "rdi",      "rdi"},
            {Identifier::rsi,      "rsi",      "rsi"},
            {Identifier::rbp,      "rbp",      "rbp"},
            {Identifier::rsp,      "rsp",      "rsp"},
            {Identifier::r8,       "r8",       "r8"},
            {Identifier::r9,       "r9",       "r9"},
            {Identifier::r10,      "r10",      "r10"},
            {Identifier::r11,      "r11",      "r11"},
            {Identifier::r12,      "r12",      "r12"},
            {Identifier::r13,      "r13",      "r13"},
            {Identifier::r14,      "r14",      "r14"},
            {Identifier::r15,      "r15",      "r15"},
            {Identifier::rip,      "rip",      "rip"},
            {Identifier::eflags,   "eflags",   "eflags"},
            {Identifier::cs,       "cs",       "cs"},
            {Identifier::orig_rax, "orig_rax", "orig_rax"},
            {Identifier::fs_base,  "fs_base",  "fs_base"},
            {Identifier::gs_base,  "gs_base",  "gs_base"},
            {Identifier::fs,       "fs",       "fs"},
            {Identifier::gs,       "gs",       "gs"},
            {Identifier::ss,       "ss",       "ss"},
            {Identifier::ds,       "ds",       "ds"},
            {Identifier::es,       "es",       "es"},
    };

    std::string_view registerNameToString(const Identifier &reg);

    Register::register_value &getRegisterReference(user_regs_struct &regsStruct, Register::Identifier registerName);

}

std::ostream &operator<<(std::ostream &os, const Register::Identifier &registryName);


#endif //SIMPLE_DEBUGGER_REGISTRY_H
