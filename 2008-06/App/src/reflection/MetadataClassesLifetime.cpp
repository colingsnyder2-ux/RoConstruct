// >>> native-status (generated) -- do not edit >>>
// MetadataClassesLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src e75e8606 | roc native-status --write
#include "reflection/Metadata.h"
namespace RBX { namespace Reflection { namespace Metadata {
Classes::Classes() {}
Classes::~Classes() {}
bool Classes::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Class*>(child) != NULL;
}
}}}
