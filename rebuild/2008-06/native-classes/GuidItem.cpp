// Inactive registry interfaces: names provisional; offsets and calls from 004b3760.
// >>> native-status (generated) -- do not edit >>>
// GuidItem | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src c2b931e2 | roc native-status --write
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

