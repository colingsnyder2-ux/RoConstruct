// >>> native-status (generated) -- do not edit >>>
// MetadataExplorerOrder | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src bd5dd1ef | roc native-status --write
#include "reflection/Metadata.h"

int RBX::Reflection::Metadata::Class::explorerOrder() const
{
    if (unknown_150)
        return unknown_150;
    if (dynamic_cast<Class*>(getParent())) {
        if (dynamic_cast<Class*>(getParent())->explorerOrder())
            return 1;
    }
    return 0;
}
