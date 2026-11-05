#include "v8datamodel/PVInstance.h"
namespace RBX {
PVInstance* PVInstance::getTopLevelPVParent() {
    PVInstance* p = this;
    while (!p->isTopLevelPVInstance()) p = static_cast<PVInstance*>(p->getParent());
    return p;
}
}
