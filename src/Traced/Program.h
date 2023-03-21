#ifndef SIMPLE_DEBUGGER_PROGRAM_H
#define SIMPLE_DEBUGGER_PROGRAM_H

#include <unordered_map>
#include <filesystem>
#include <thread>
#include <vector>
#include "Breakpoint.h"

namespace fs = std::filesystem;

class Program {
    using self = Program;
public:
    pid_t getPid() const;

    bool setBreakpoint(std::intptr_t address);

    bool removeBreakpoint(std::intptr_t address);

    bool hasBreakpoint(std::intptr_t address);

    Breakpoint getBreakpoint(std::intptr_t address);

    void run();

    void checkBreakpoints(pid_t pid);

private:
public:
    Program(fs::path mPath, const std::vector<std::string> &mArguments);

private:
    void start();

    std::unordered_map<std::intptr_t, Breakpoint> m_breakPoints;

    pid_t m_pid{};
    fs::path m_path;
    std::vector<std::string> m_arguments;
    std::thread m_thread;
};

#endif //SIMPLE_DEBUGGER_PROGRAM_H
