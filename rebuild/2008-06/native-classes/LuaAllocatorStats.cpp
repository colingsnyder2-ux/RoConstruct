// >>> native-status (generated) -- do not edit >>>
// LuaAllocatorStats | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src a174770c | roc native-status --write
#include <cstddef>
#include "script/LuaMemory.h"

void LuaAllocator::getHeapStats(size_t& bytes, size_t& blocks) const
{
    bytes = heapSize;
    blocks = heapCount;
}
