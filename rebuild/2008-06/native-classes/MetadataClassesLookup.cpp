#include "reflection/Metadata.h"
#include "reflection/reflection.h"
namespace RBX { namespace Reflection { namespace Metadata {
Class* Classes::lookup(const ClassDescriptor& descriptor, bool recursive) const
{
    Class* found = static_cast<Class*>(findFirstChildByName(descriptor.name.toString()));
    if (found) return found;
    if (recursive && descriptor.getBase()) return lookup(*descriptor.getBase(), true);
    return NULL;
}
}}}
