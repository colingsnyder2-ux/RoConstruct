#include "reflection/property.h"
#include "reflection/type.h"

namespace RBX {
namespace Reflection {

// The reconstructed Value::operator=<DescribedBase*> instantiates the matching
// Type singleton. The original 2008 client used the shared_ptr<DescribedBase>
// "Object" type instead, but this header's getRefValue() returns a raw
// DescribedBase*, so provide the raw-pointer singleton using the same authentic
// explicit-specialization pattern as AppUnit564_2008Type.cpp (0056ca70).
template<>
const Type& Type::singleton<DescribedBase*>()
{
    static Type type("Object", typeid(DescribedBase*));
    return type;
}

bool RefPropertyDescriptor::isWriteOnly() const
{
    return false;
}

void RefPropertyDescriptor::getVariant(const DescribedBase* instance, Value& value) const
{
    value = getRefValue(instance);
}

void RefPropertyDescriptor::setVariant(DescribedBase* instance, const Value& value) const
{
    setRefValue(instance, value.cast<DescribedBase*>());
}

}
}
