#include <cstddef>
#include "script/LuaMemory.h"

void LuaAllocator::getHeapStats(size_t& bytes, size_t& blocks) const
{
    bytes = heapSize;
    blocks = heapCount;
}
