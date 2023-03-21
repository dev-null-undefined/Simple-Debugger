#include "Continue.h"

void Continue::execute(Controller &controller, const std::vector<std::string> &args) {
    controller.getTracer().continueExecution();
}

std::string Continue::getName() const {
    return "continue";
}
