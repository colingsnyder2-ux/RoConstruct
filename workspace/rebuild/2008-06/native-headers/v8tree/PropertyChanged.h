#pragma once
// >>> native-status (generated) -- do not edit >>>
// PropertyChanged | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b0fcf29e | roc native-status --write
#include "reflection/property.h"

namespace RBX {
class Instance;
// Existing donor event declaration; original grid callback observes its descriptor.
class PropertyChanged {
    friend class Instance;
    Reflection::Property property;
public:
    bool getProperty(Reflection::Property*&);
    const Reflection::Property& getProperty() const { return property; }
    const Reflection::PropertyDescriptor& getDescriptor() { return property.getDescriptor(); }
    const Name& getName();
    PropertyChanged(const PropertyChanged&);
private:
    PropertyChanged(const Reflection::Property& value)
        : property(Reflection::Property(value.getDescriptor(), value.getInstance())) {}
};
}
