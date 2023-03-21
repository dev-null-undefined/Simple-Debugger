#include "DumpRegisters.h"

void DumpRegisters::execute(Debugger &controller, const std::vector<std::string> &args) {
    controller.getTracer().dumpRegisters();
}

std::string DumpRegisters::getName() const {
    return "dump_registers";
}