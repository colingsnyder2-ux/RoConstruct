#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
namespace RBX {
void Instance::raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor) {
    PropertyChanged event(Reflection::Property(descriptor, this));
    Notifier<Instance, PropertyChanged>::raise(event);
    if (!event_propertyChanged.empty(this)) event_propertyChanged.fire(this, &descriptor);
    Instance* p = parent;
    if (p) p->onChildChanged(this, event);
}
}

