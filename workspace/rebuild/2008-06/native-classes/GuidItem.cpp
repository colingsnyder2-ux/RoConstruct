// Inactive registry interfaces: names provisional; offsets and calls from 004b3760.
// >>> native-status (generated) -- do not edit >>>
// GuidItem | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 59781a69 | roc native-status --write
#include "v8tree/Instance.h"
#include "util/GuidRegistry.h"
#include <boost/thread/once.hpp>
namespace RBX {
extern GuidRegistry* guidRegistry;
extern boost::once_flag guidRegistryInitialized;
extern void initializeGuidRegistry();
struct GuidRegistryLock {
    GuidRegistryMutex* mutex; bool locked;
    GuidRegistryLock(GuidRegistryMutex& value) : mutex(&value), locked(false) { mutex->lock(); locked = true; }
    ~GuidRegistryLock() { if (locked) mutex->unlock(); }
};
template<class T> GuidItem<T>::~GuidItem()
{
    if (registeredGuid) {
        Guid::Data key;
        guid.extract(key);
        boost::call_once(initializeGuidRegistry, guidRegistryInitialized);
        GuidRegistry* value = guidRegistry;
        GuidRegistryLock lock(value->mutex);
        value->tree.erase(key);
    }
    registeredGuid = false;
}
template GuidItem<Instance>::~GuidItem();
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tmap_traits<RBX::Guid::Data,RBX::Instance *,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Guid::Data,RBX::Instance *,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> >,0> >;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Guid::Data,RBX::Instance *,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Guid::Data,RBX::Instance *,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> >,0> >::iterator>;
