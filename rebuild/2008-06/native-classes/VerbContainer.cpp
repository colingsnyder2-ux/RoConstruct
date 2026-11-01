#include "../native-headers/v8tree/VerbContainer.h"

RBX::VerbContainer::VerbContainer(VerbContainer* parent) : parent(parent) {}

void RBX::VerbContainer::setVerbParent(VerbContainer* parent)
{
    this->parent = parent;
}
