// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// CollectDragParts | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 10171339 | roc native-status --write
#include "v8datamodel/PartInstance.h"
#include <boost/weak_ptr.hpp>
#include <vector>

namespace RBX {
void collectDragParts(const std::vector<Instance*>& instances, std::vector<boost::weak_ptr<PartInstance> >& parts)
{
    for (unsigned i = 0; i < instances.size(); ++i)
        PartInstance::findParts(instances[i], parts);
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::vector<RBX::Instance *,std::allocator<RBX::Instance *> >;
