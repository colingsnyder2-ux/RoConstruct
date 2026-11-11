// >>> native-status (generated) -- do not edit >>>
// LuaAllocatorStats | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src a174770c | roc native-status --write
#include <cstddef>
#include "script/LuaMemory.h"

void LuaAllocator::getHeapStats(size_t& bytes, size_t& blocks) const
{
    bytes = heapSize;
    blocks = heapCount;
}
