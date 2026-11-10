#include "NativeModelToolsTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
const std::string LockTool::getCursorName() const {
    if (target) {
        bool locked = PartInstance::getLocked(target.get());
        if (locked) return "UnlockCursor";
        return "LockCursor";
    }
    return "LockCursor";
}
}
