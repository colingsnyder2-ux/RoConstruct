#include "v8tree/Instance.h"

void RBX::Instance::setName(const std::string& value) {
    if (name != value) {
        name = value;
        raisePropertyChanged(desc_Name);
    }
}

bool RBX::Instance::askAddChild(const Instance*) const { return false; }
bool RBX::Instance::askSetParent(const Instance*) const { return false; }

void RBX::Instance::onChildAdded(Instance*) {}
void RBX::Instance::onChildRemoving(Instance*) {}
void RBX::Instance::onChildRemoved(Instance*) {}
void RBX::Instance::onLastChildRemoved() {}
// Original 00458e90 returns without modifying either service provider.
void RBX::Instance::onServiceProvider(const ServiceProvider*, const ServiceProvider*) {}

void RBX::Instance::onChildChanged(Instance* instance, const PropertyChanged& event)
{
    Instance* p = parent;
    if (p) p->onChildChanged(instance, event);
}
