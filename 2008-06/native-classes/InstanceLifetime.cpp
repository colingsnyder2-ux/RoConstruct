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
