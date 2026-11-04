#include "util/Guid.h"
#include <map>

namespace RBX {
struct GuidRegistryMutex {
    void* handle; bool criticalSection; unsigned int count;
    GuidRegistryMutex();
    ~GuidRegistryMutex();
    void lock();
    void unlock();
};
class Instance;
struct GuidRegistry : std::map<Guid::Data, Instance*> {
    GuidRegistryMutex mutex;
    GuidRegistry();
    void remove(const Guid::Data&);
};
typedef char GuidRegistrySize[sizeof(GuidRegistry) == 0x2c ? 1 : -1];
GuidRegistry::GuidRegistry() : mutex() {}
void GuidRegistry::remove(const Guid::Data& data) { erase(data); }
}
