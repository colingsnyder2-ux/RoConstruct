// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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
