#include <ranges>
#include "ActionManager.h"


ActionPtr ActionManager::getAction(const std::string &command) {
    size_t maxPriority = 0;
    ActionPtr maxPriorityAction = nullptr;
    for (const auto &action: ACTIONS) {
        size_t priority = action->matches(command);
        if (priority > maxPriority) {
            maxPriority = priority;
            maxPriorityAction = action;
        } else if (priority == maxPriority) {
            maxPriority = 0;
        }
    }
    if (maxPriority == 0)
        return nullptr;
    return maxPriorityAction;
}

void ActionManager::addAction(const ActionPtr &action) {
#ifdef DEBUG
    if (std::ranges::find(ACTIONS, action.get(), [](const ActionPtr &a) { return a.get(); }) != ACTIONS.end())
        throw std::runtime_error("Action already added");
#endif
    ACTIONS.push_back(action);
}


std::vector<ActionPtr> ActionManager::ACTIONS = {};