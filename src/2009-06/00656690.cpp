// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <algorithm>
#include <stddef.h>

struct BucketAllocator
{
    void* realloc(void* ptr, size_t osize, size_t nsize);
};

class LuaAllocator
{
public:
    void* alloc(void* ptr, size_t osize, size_t nsize);
private:
    size_t heapSize;
    size_t heapCount;
    size_t maxHeapSize;
    size_t maxHeapCount;
    BucketAllocator buckets;
};

void* LuaAllocator::alloc(void* ptr, size_t osize, size_t nsize)
{
    void* result = buckets.realloc(ptr, osize, nsize);

    heapSize += (nsize-osize);

    if (osize == 0)
        heapCount++;

    if (nsize == 0)
        heapCount--;

    maxHeapSize = std::max<size_t>(maxHeapSize, heapSize);
    maxHeapCount = std::max<size_t>(maxHeapCount, heapCount);

    return result;
}
