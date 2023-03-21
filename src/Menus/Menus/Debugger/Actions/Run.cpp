#include "Run.h"
#include "../Debugger.h"

void Run::execute(Debugger &controller, const std::vector<std::string> &args) {
    const std::string &path = args[1];
    std::vector<std::string> program_args;
    for (size_t i = 2; i < args.size(); ++i) {
        program_args.push_back(args[i]);
    }
    Program program(path, program_args);
    Tracer tracer(std::move(program));
    controller.setTracer(std::move(tracer));
}

std::string Run::getName() const {
    return "run";
}
