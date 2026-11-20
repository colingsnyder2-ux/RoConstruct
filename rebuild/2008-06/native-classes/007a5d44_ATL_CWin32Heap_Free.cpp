// native-flags: /O2 /GS- /MD /hotpatch
// native-archive: msvc-atlmfc-rtm atls.lib
// 2008-06 native ATL::CWin32Heap::Free (inactive)
// Assembly: mov edi, edi; push ebp; mov ebp, esp; cmp [ebp+8], 0; je skip; push [ebp+8]; push 0; push [ecx+4]; call [0x8021f0] (HeapFree); skip: pop ebp; ret 4
// This source uses the ATL archive recipe to match the prebuilt atls.lib object
// The actual source is in the ATL static library (atls.lib)
// INFERRED: CWin32Heap::Free matches the binary at 007a5d44

// Force reference to CWin32Heap::Free to pull it from the archive
#include <atlbase.h>
#include <atlmem.h>

void reference_CWin32Heap_Free()
{
    ATL::CWin32Heap heap(0, 0, 0);
    void* p = heap.Allocate(16);
    if (p)
    {
        heap.Free(p);  // This should pull Free from atls.lib
    }
}