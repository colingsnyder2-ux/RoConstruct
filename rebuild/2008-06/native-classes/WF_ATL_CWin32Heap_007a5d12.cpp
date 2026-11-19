// native-flags: /O2 /GS- /MD /hotpatch
#include <atlbase.h>
#include <atlmem.h>

// The real ATL header defines CWin32Heap inline, so this file includes it and
// forces emission of its members, including the vtable and destructor.
void ForceCWin32Heap()
{
    ATL::CWin32Heap heap(0, 0, 0);
    void* p = heap.Allocate(16);
    p = heap.Reallocate(p, 32);
    heap.GetSize(p);
    heap.Free(p);
}
