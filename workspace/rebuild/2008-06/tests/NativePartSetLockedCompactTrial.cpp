#include "v8datamodel/PartInstance.h"
namespace RBX {
void PartInstance::setLocked(Instance* object, bool value) {
    if (PartInstance* part = dynamic_cast<PartInstance*>(object)) {
        bool& locked = *reinterpret_cast<bool*>(reinterpret_cast<char*>(part) + 0x1f0);
        if (value != locked) { locked = value; part->raisePropertyChanged(prop_Locked); }
    } else {
        for (unsigned int i=0; i<object->numChildren(); ++i) setLocked(object->getChild(i), value);
    }
}
}
