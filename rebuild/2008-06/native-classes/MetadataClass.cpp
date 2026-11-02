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
    return std::max(unknown_154, 0);
}

} // namespace Metadata
} // namespace Reflection
} // namespace RBX
