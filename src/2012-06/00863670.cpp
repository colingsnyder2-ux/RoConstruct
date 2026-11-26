// from server: 100% by Xemicl
// roc 2012-06 00863670  unit: VWiniInetRequest_source::?$stream_buffer  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00863670
//
// 00863670  56                   push esi
// 00863671  8b742408             mov esi, dword ptr [esp + 8]
// 00863675  8d4610               lea eax, [esi + 0x10]
// 00863678  83c9ff               or ecx, 0xffffffff
// 0086367b  f00fc108             lock xadd dword ptr [eax], ecx
// 0086367f  7532                 jne 0x8636b3
// 00863681  85f6                 test esi, esi
// 00863683  742e                 je 0x8636b3
// 00863685  8b4604               mov eax, dword ptr [esi + 4]
// 00863688  57                   push edi
// 00863689  8b3de821b200         mov edi, dword ptr [0xb221e8]
// 0086368f  85c0                 test eax, eax
// 00863691  7408                 je 0x86369b
// 00863693  83f8ff               cmp eax, -1
// 00863696  7403                 je 0x86369b
// 00863698  50                   push eax
// 00863699  ffd7                 call edi
// 0086369b  8b06                 mov eax, dword ptr [esi]
// 0086369d  85c0                 test eax, eax
// 0086369f  7408                 je 0x8636a9
// 008636a1  83f8ff               cmp eax, -1
// 008636a4  7403                 je 0x8636a9
// 008636a6  50                   push eax
// 008636a7  ffd7                 call edi
// 008636a9  56                   push esi
// 008636aa  e865ea1100           call 0x982114
// 008636af  83c404               add esp, 4
// 008636b2  5f                   pop edi
// 008636b3  5e                   pop esi
// 008636b4  c3                   ret 
// copied from an identical function in another client (function ?intrusive_ptr_release@@YAXPAUthread_data@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct handle_manager {
    void* h;
    ~handle_manager() { if (h && h != (void*)-1) CloseHandle(h); }
};
struct thread_data {
    handle_manager thread_handle;
    handle_manager interruption_handle;
    int a, b;
    long count;
};
void intrusive_ptr_release(thread_data* p)
{
    if (!_InterlockedDecrement(&p->count))
        delete p;
}