#include "ShortCut.h"

bool ShortCut::isShortcut() const {
    return true;
}

size_t ShortCut::matches(const std::string &command) const {
    if(shortCutMatches(command))
        return -1;
    return Action::matches(command);
}
