#include "NativeModelToolsTrial.h"
namespace RBX {
const std::string AnchorTool::getCursorName() const {
    if (target) {
        if (anchored) return "UnAnchorCursor";
        return "AnchorCursor";
    }
    return "AnchorCursor";
}
}
