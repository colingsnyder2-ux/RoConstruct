// >>> native-status (generated) -- do not edit >>>
// MetadataClass | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (deepseek:deepseek-flash)
// <<< native-status | src afa929f6 | roc native-status --write
#include "reflection/Metadata.h"
#include <algorithm>

namespace RBX {
namespace Reflection {
namespace Metadata {

// 0041fb30: an unset (-1) index defers to the parent Class; the target keeps the bool-valued
// recursion result (setne/movzx), so the expression is preserved as compiled.
int Class::getImageIndex() const {
    if (unknown_154 == -1)
        return dynamic_cast<const Class*>(getParent()) && dynamic_cast<const Class*>(getParent())->getImageIndex();
    return (std::max)(unknown_154, 0);
}

} // namespace Metadata
} // namespace Reflection
} // namespace RBX
