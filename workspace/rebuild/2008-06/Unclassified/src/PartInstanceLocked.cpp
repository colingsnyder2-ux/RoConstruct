#include "../../native-headers/v8datamodel/PartInstance.h"

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
