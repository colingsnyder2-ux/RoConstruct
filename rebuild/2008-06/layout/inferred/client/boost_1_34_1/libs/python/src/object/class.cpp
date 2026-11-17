#include "reflection/Metadata.h"
#include <algorithm>

namespace RBX {
namespace Reflection {
namespace Metadata {

int Class::getImageIndex() const {
    if (unknown_154 == -1)
        return dynamic_cast<const Class*>(getParent()) && dynamic_cast<const Class*>(getParent())->getImageIndex();
    return (std::max)(unknown_154, 0);
}

} // namespace Metadata
} // namespace Reflection
} // namespace RBX
