#include "script/ScriptContext.h"
#include <cstddef>
typedef char ScriptContextSize[sizeof(RBX::ScriptContext) == 0x1f8 ? 1 : -1];
typedef char ScriptContextAllocatorOffset[offsetof(RBX::ScriptContext, allocator) == 0x1f0 ? 1 : -1];
