// >>> native-status (generated) -- do not edit >>>
// MetadataExplorerOrder | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-chat)
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
