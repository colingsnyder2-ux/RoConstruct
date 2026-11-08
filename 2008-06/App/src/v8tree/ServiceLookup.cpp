// >>> native-status (generated) -- do not edit >>>
// ServiceLookup | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f5a3caa5 | roc native-status --write
#include "v8tree/Service.h"

size_t RBX::ServiceProvider::newIndex()
{
    static size_t index = 0xffffffff;
    return InterlockedIncrement(reinterpret_cast<LONG*>(&index));
}

boost::shared_ptr<RBX::Instance> RBX::ServiceProvider::findServiceByClassName(const Name& name) const
{
    std::map<const Name*, boost::shared_ptr<Instance> >::const_iterator it = serviceMap.find(&name);
    if (it != serviceMap.end()) return it->second;
    return boost::shared_ptr<Instance>();
}
