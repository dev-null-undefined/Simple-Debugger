#include "Break.h"

void Break::execute(Controller &controller, const std::vector<std::string> &args) {
    intptr_t address = std::stol(args[1], nullptr, 16);
    controller.getTracer().setBreakpoint(address);
}

std::string Break::getName() const {
    return "break";
}
