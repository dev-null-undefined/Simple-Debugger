#include "Break.h"

void Break::execute(Debugger &controller, const std::vector<std::string> &args) {
    intptr_t address = std::stol(args[1], nullptr, 16);
    controller.getTracer().setBreakpoint(address);
}

std::string Break::getName() const {
    return "break";
}
