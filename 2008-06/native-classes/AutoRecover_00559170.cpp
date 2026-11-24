// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h"
#include "v8xml/XmlElement.h"

namespace RBX {

// INFERRED: global at 0x00975338 is a reference to the "name" attribute Name
// (the code loads the stored pointer and passes it straight through as const Name&).
extern const Name& g_00975338;

// INFERRED: follows the later Roblox source of Instance::readProperty:
// DescribedBase::findProperty (inlined: ClassDescriptor's property container
// findDescriptor + Iterator ctor) compared against properties_end(), then
// the descriptor's virtual readValue (vtable +0x24) on the dereferenced Property.
void Instance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
    const Name* name = NULL;
    const XmlAttribute* nameAttribute = propertyElement->findAttribute(g_00975338);
    if (nameAttribute && nameAttribute->getValue(name))
    {
        Reflection::PropertyIterator iter = findProperty(*name);
        if (iter != properties_end())
        {
            Reflection::Property property = *iter;
            property.getDescriptor().readValue(property.getInstance(), propertyElement, binder);
        }
    }
}

} // namespace RBX
