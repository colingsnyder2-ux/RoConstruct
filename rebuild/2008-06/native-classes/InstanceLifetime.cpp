// Inactive candidate: lifetime bodies match; dependent ABI and linkage remain open.
#include "v8tree/Instance.h"
#include <windows.h>
namespace RBX {
extern long instanceCount;
Instance::Instance() : parent(0), name("Instance"), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::~Instance()
{
    InterlockedDecrement(&instanceCount);
}
}

boost::shared_ptr<RBX::Instance> RBX::Instance::createChild(const Name& className)
{
    return AbstractFactoryProduct::create(className);
}