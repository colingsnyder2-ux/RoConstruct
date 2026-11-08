// >>> native-status (generated) -- do not edit >>>
// VerbContainer | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d0bb9549 | roc native-status --write
#include "../../native-headers/v8tree/VerbContainer.h"

RBX::VerbContainer::VerbContainer(VerbContainer* parent) : parent(parent) {}

void RBX::VerbContainer::setVerbParent(VerbContainer* parent)
{
    this->parent = parent;
}
