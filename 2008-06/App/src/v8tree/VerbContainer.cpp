// >>> native-status (generated) -- do not edit >>>
// VerbContainer | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 7b0c5d1d | roc native-status --write
#include "../../../native-headers/v8tree/VerbContainer.h"

RBX::VerbContainer::VerbContainer(VerbContainer* parent) : parent(parent) {}

void RBX::VerbContainer::setVerbParent(VerbContainer* parent)
{
    this->parent = parent;
}
