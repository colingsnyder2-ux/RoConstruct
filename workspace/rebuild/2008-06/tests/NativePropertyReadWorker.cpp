#include "reflection/property.h"
namespace RBX { namespace Reflection {
void PropertyDescriptor::read(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const { readValue(instance, element, binder); }
}}
