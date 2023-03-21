#include <string>
#include <iostream>
#include <vector>
#include <ranges>
#include "Controller.h"
#include "../Algorithms.h"
#include "Action.h"


std::string readInput(std::string & input) {
    std::cout << ">> " << std::flush;
    input.clear();
    std::getline(std::cin, input);
    return input;
}

void Controller::start() {
    std::string command;

    while (std::cin){
        readInput(command);
        if(command.empty())
            continue;
        std::vector<std::string> splitCommand = split(command, " ");
        ActionPtr action = getAction(splitCommand[0]);
        if (action == nullptr) {
            std::cout << "Unknown command" << std::endl;
        } else {
            action->execute(*this,splitCommand);
        }
    }
}


Tracer &Controller::getTracer() {
    return *m_tracer;
}

ActionPtr Controller::getAction(const std::string &command) {
    size_t maxPriority = 0;
    ActionPtr maxPriorityAction = nullptr;
    for(const auto &action : m_actions){
        size_t priority = action->matches(command);
        if(priority > maxPriority){
            maxPriority = priority;
            maxPriorityAction = action;
        } else if(priority == maxPriority){
            maxPriority = 0;
        }
    }
    if(maxPriority == 0)
        return nullptr;
    return maxPriorityAction;
}

void Controller::addAction(const ActionPtr& action) {
#ifdef DEBUG
    if(std::ranges::find(m_actions, action.get(), [](const ActionPtr & a){return a.get();}) != m_actions.end())
        throw std::runtime_error("Action already added");
#endif
    m_actions.push_back(action);
}

void Controller::setTracer(Tracer &&tracer) {
    m_tracer = std::move(tracer);
}

std::vector<ActionPtr> Controller::m_actions = {};