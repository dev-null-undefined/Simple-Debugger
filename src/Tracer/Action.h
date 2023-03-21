#ifndef SIMPLE_DEBUGGER_ACTION_H
#define SIMPLE_DEBUGGER_ACTION_H

#include <memory>
#include <vector>
#include "Controller.h"

class Action {
protected:
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const;
    virtual std::string getUsage() const;
    virtual size_t getPriority() const;
public:
    using ActionPtr = std::shared_ptr<Action>;

    static void registerAction(const ActionPtr& action);
    [[nodiscard]] virtual size_t matches(const std::string &command) const;
    virtual void execute(Controller & controller, const std::vector<std::string> &args) = 0;
    virtual ~Action() = default;
    bool operator==(const Action &rhs) const;
};


#endif //SIMPLE_DEBUGGER_ACTION_H
