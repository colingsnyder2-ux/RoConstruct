// Inactive registry interfaces: names provisional; offsets and calls from 004b3760.
#include "v8tree/Instance.h"
#include <boost/thread/once.hpp>
namespace RBX {
struct GuidRegistryMutex {
    void* handle; bool criticalSection; unsigned int count;
    void lock();
    void unlock();
};
struct GuidRegistry {
    char storage[32];
    GuidRegistryMutex mutex;
    void remove(const Guid::Data&);
};
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
        value->remove(key);
    }
    registeredGuid = false;
}
template GuidItem<Instance>::~GuidItem();
}

