// >>> native-status (generated) -- do not edit >>>
// MetadataClassesLifetime | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
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
