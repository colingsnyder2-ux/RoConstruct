#pragma once
// >>> native-status (generated) -- do not edit >>>
// GuidRegistry | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 70cb57f8 | roc native-status --write
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
