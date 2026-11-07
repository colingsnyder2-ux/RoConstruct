// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// CollectDragParts | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 30554962 | roc native-status --write
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
