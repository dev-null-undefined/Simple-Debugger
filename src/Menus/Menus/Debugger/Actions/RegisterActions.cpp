
#include <memory>
#include "Continue.h"
#include "Break.h"
#include "DumpRegisters.h"
#include "Run.h"
#include "Start.h"

void registerActions() {
    Action::registerAction(std::make_shared<DumpRegisters>());
    Action::registerAction(std::make_shared<Break>());
    Action::registerAction(std::make_shared<Continue>());
    Action::registerAction(std::make_shared<Run>());
    Action::registerAction(std::make_shared<Start>());
}
