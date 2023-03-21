#include "Program.h"
#include <sys/ptrace.h>
#include <sys/personality.h>
#include <cstring>
#include <utility>
#include <iostream>


void Program::run() {
    pid_t pid = fork();
    if (pid == 0) {
        start();
    } else {
        m_pid = pid;
    }
}

void Program::start() {
    ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
    char **args = new char *[m_arguments.size() + 1];
    for (size_t i = 0; i < m_arguments.size(); ++i) {
        size_t max_size = m_arguments[i].size() + 1;
        args[i] = new char[max_size];
        strncpy(args[i], m_arguments[i].c_str(), max_size - 1);
    }
    args[m_arguments.size()] = nullptr;
    personality(ADDR_NO_RANDOMIZE);
    execv(m_path.c_str(), args);
    for (size_t i = 0; i < m_arguments.size(); ++i) {
        delete[] args[i];
    }
    delete[] args;
}

bool Program::setBreakpoint(std::intptr_t address) {
    if (m_breakPoints.count(address) == 0) {
        Breakpoint breakpoint(m_pid, address);
        breakpoint.enable();
        m_breakPoints.emplace(address, breakpoint);
        return true;
    }
    return false;
}

bool Program::removeBreakpoint(std::intptr_t address) {
    if (auto breakpoint = m_breakPoints.find(address); breakpoint != m_breakPoints.end()) {
        breakpoint->second.disable();
        m_breakPoints.erase(breakpoint);
        return true;
    }
    return false;
}

pid_t Program::getPid() const {
    return m_pid;
}

Breakpoint Program::getBreakpoint(std::intptr_t address) {
    return m_breakPoints.at(address);
}

bool Program::hasBreakpoint(std::intptr_t address) {
    std::cout << "Checking for breakpoint at " << address << ", result:" << std::boolalpha
              << (m_breakPoints.count(address) != 0) << std::endl;
    return m_breakPoints.count(address) != 0;
}

Program::Program(fs::path mPath, const std::vector<std::string> &mArguments) : m_path(std::move(mPath)),
                                                                               m_arguments(mArguments) {}

void Program::checkBreakpoints(pid_t pid) {
    for (auto &[address, breakpoint]: m_breakPoints) {
        if (breakpoint.getState() == Breakpoint::State::TO_BE_ENABLED) {
            breakpoint.setPid(pid);
            std::cout << "Enabling breakpoint at " << std::hex << address << ", " << breakpoint.isEnabled() << std::endl;
        }
    }
}
