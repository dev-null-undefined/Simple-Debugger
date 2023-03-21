#include "Start.h"
#include "../Debugger.h"

void Start::execute(Debugger &controller, const std::vector<std::string> &args) {
    controller.getTracer().run();
}

std::string Start::getName() const {
    return "start";
}
