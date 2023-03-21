#include "DumpRegisters.h"
#include "../../../../Algorithms.h"

void DumpRegisters::execute(Debugger &controller, const std::vector<std::string> &args) {
    std::stringstream ss;
    controller.getTracer().dumpRegisters(ss);
    auto lines = split(ss.str(), "\n");
    controller.printLines(lines);
}

std::string DumpRegisters::getName() const {
    return "dump_registers";
}
