// Inactive candidate: lifetime bodies match; dependent ABI and linkage remain open.
// >>> native-status (generated) -- do not edit >>>
// InstanceLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 67be2023 | roc native-status --write
#include "v8tree/Instance.h"
#include <windows.h>
namespace RBX {
extern long instanceCount;
Instance::Instance() : parent(0), name("Instance"), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::Instance(const char* value) : parent(0), name(value), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::~Instance()
{
    InterlockedDecrement(&instanceCount);
}
}

#ifndef NATIVE_INSTANCE_EXTERNAL_CREATE_CHILD
boost::shared_ptr<RBX::Instance> RBX::Instance::createChild(const Name& className)
{
    return AbstractFactoryProduct::create(className);
}
#endif
