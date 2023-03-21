#include "Action.h"
#include "../../../Algorithms.h"
#include "ActionManager.h"

size_t Action::matches(const std::string &command) const {
    if (hasPrefix(getName(), command)) {
        return getPriority();
    } else {
        return 0;
    };
}

bool Action::operator==(const Action &rhs) const {
    return getName() == rhs.getName();
}

void Action::registerAction(const ActionPtr &action) {
    ActionManager::addAction(action);
}

size_t Action::getPriority() const {
    return 1;
}

std::string Action::getDescription() const {
    return std::string();
}

std::string Action::getUsage() const {
    return std::string();
}

bool Action::isShortcut() const {
    return false;
}
