// >>> native-status (generated) -- do not edit >>>
// MetadataReflectionLookup | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 94df1015 | roc native-status --write
#include "reflection/Metadata.h"
namespace RBX { namespace Metadata {
RBX::Reflection::Metadata::Class* Reflection::lookup(const RBX::Reflection::ClassDescriptor& descriptor, bool recursive) const
{
    return classes ? classes->lookup(descriptor, recursive) : NULL;
}
}}
