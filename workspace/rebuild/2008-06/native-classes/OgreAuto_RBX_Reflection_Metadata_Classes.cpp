// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/reflection/Metadata.h"

namespace RBX {
namespace Reflection {
namespace Metadata {
void Classes::addClass(const RBX::Reflection::ClassDescriptor& descriptor)
{
    Instance* existing;
    {
        const std::string& key = descriptor.name.name;
        existing = findFirstChildByName(key);
    }
    if (existing) {
        static_cast<Item*>(existing)->unknown_130 = false;
        return;
    }

    boost::shared_ptr<Class> c = Creatable<Instance>::create<Class>();
    c.get()->setName(descriptor.name.name);
    c.get()->unknown_130 = false;
    c.get()->setParent(this);
}
}
}
}

namespace RBX {
namespace Reflection {
namespace Metadata {
RBX::Reflection::Metadata::Class* Classes::lookup(const RBX::Reflection::ClassDescriptor& descriptor, bool recursive) const
{
    Instance* result = findFirstChildByName(descriptor.name.toString());
    if (result)
        return static_cast<Class*>(result);

    if (recursive && descriptor.getBase())
        return lookup(*descriptor.getBase(), true);

    return 0;
}
}
}
}

