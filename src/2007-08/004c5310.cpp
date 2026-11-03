// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
#include <stdlib.h>
namespace DataStructures {
template<class MemoryBlockType>
class MemoryPool
{
public:
    struct Page;
    struct MemoryWithPage
    {
        MemoryBlockType userMemory;
        Page* parentPage;
    };
    struct Page
    {
        MemoryWithPage** availableStack;
        int availableStackSize;
        MemoryWithPage* block;
        Page *next, *prev;
    };
    void Clear(void);
protected:
    Page *availablePages, *unavailablePages;
    int availablePagesSize, unavailablePagesSize;
    int memoryPoolPageSize;
};

template<class MemoryBlockType>
void MemoryPool<MemoryBlockType>::Clear(void)
{
    Page *cur, *freed;

    if (availablePagesSize > 0)
    {
        cur = availablePages;
        do
        {
            free(cur->availableStack);
            free(cur->block);
            freed = cur;
            cur = cur->next;
            free(freed);
        } while (cur != availablePages);
    }

    if (unavailablePagesSize > 0)
    {
        cur = unavailablePages;
        do
        {
            free(cur->availableStack);
            free(cur->block);
            freed = cur;
            cur = cur->next;
            free(freed);
        } while (cur != unavailablePages);
    }

    availablePagesSize = 0;
    unavailablePagesSize = 0;
}
}
struct InternalPacket { char data[0x40]; };
template class DataStructures::MemoryPool<InternalPacket>;
