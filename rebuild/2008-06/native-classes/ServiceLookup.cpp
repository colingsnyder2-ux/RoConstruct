// >>> native-status (generated) -- do not edit >>>
// ServiceLookup | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 0a71f589 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0> >;
