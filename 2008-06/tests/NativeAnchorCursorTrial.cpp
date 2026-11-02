#include "NativeModelToolsTrial.h"
namespace RBX {
const std::string AnchorTool::getCursorName() const {
    return target && anchored ? "UnAnchorCursor" : "AnchorCursor";
}
MouseCommand* AnchorTool::isSticky() const { return NULL; }
}
