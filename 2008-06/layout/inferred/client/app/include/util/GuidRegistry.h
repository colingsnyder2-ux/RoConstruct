#pragma once
#include "util/Guid.h"
#include <map>

namespace RBX {
class Instance;
struct GuidRegistryMutex {
    void* handle; bool criticalSection; unsigned int count;
    GuidRegistryMutex();
    ~GuidRegistryMutex();
    void lock();
    void unlock();
};
struct GuidRegistry {
    std::map<Guid::Data, Instance*> tree;
    GuidRegistryMutex mutex;
    GuidRegistry();
};
}
