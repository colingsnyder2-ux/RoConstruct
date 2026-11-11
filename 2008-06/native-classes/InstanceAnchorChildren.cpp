// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/cow-noinline-read
// >>> native-status (generated) -- do not edit >>>
// InstanceAnchorChildren | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-chat)
// <<< native-status | src 924ea143 | roc native-status --write
#include "v8datamodel/PartInstance.h"

namespace RBX {
void Instance::applyAnchoredToChildren(AnchorAction value)
{
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = children.read();
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = list->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = list->begin();
        for (; it != end; ++it) {
            Instance* child = it->get();
            if (PartInstance* part = dynamic_cast<PartInstance*>(child))
                part->setAnchored(value.value);
            else
                child->applyAnchoredToChildren(value);
        }
    }
}
}
