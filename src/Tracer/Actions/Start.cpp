#include "Start.h"

void Start::execute(Controller &controller, const std::vector<std::string> &args) {
    controller.getTracer().run();
}

std::string Start::getName() const {
    return "start";
}
