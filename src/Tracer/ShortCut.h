#ifndef SIMPLE_DEBUGGER_SHORTCUT_H
#define SIMPLE_DEBUGGER_SHORTCUT_H


#include "../Menus/Menus/Debugger/Action.h"

class ShortCut : public Action {
public:
    [[nodiscard]] virtual bool shortCutMatches(const std::string &command) const = 0;

    [[nodiscard]] size_t matches(const std::string &command) const override;

    [[nodiscard]] bool isShortcut() const override;
};


#endif //SIMPLE_DEBUGGER_SHORTCUT_H
