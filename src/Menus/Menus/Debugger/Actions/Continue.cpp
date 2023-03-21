#include "Continue.h"

void Continue::execute(Debugger &controller, const std::vector<std::string> &args) {
    controller.getTracer().continueExecution();
}

std::string Continue::getName() const {
    return "continue";
}
