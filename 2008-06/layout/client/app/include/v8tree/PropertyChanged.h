#pragma once
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
