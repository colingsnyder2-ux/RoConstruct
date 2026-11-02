#include "v8tree/Instance.h"

bool RBX::Instance::askAddChild(const Instance*) const { return false; }
bool RBX::Instance::askSetParent(const Instance*) const { return false; }

void RBX::Instance::onChildAdded(Instance*) {}
void RBX::Instance::onChildRemoving(Instance*) {}
void RBX::Instance::onChildRemoved(Instance*) {}
void RBX::Instance::onLastChildRemoved() {}

void RBX::Instance::onChildChanged(Instance* instance, const PropertyChanged& event)
{
    Instance* p = parent;
    if (p) p->onChildChanged(instance, event);
}
