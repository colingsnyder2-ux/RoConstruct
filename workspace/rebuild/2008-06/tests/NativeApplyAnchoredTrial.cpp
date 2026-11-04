#include "v8datamodel/PartInstance.h"
namespace RBX {
void nativeApplyAnchored(Instance* instance, const bool& value) {
    bool local = value;
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        part->setAnchored(local);
    else {
        Instance::AnchorAction action = { local };
        instance->applyAnchoredToChildren(action);
    }
}
}
