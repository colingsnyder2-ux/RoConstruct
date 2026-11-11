// >>> native-status (generated) -- do not edit >>>
// PartInstanceLocked | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 1ad8bb1e | roc native-status --write
#include "../native-headers/v8datamodel/PartInstance.h"

namespace RBX {

void PartInstance::setLocked(Instance* object, bool value) {
	if (PartInstance* part = dynamic_cast<PartInstance*>(object)) {
		if (value != part->locked) {
			part->locked = value;
			part->raisePropertyChanged(prop_Locked);
		}
	} else {
		for (unsigned int i = 0; i < object->numChildren(); ++i)
			setLocked(object->getChild(i), value);
	}
}

}
