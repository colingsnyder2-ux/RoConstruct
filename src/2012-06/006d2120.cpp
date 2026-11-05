// roc 2012-06 006d2120  unit: VThreadLogManager::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d2120
//
// 006d2120  56                   push esi
// 006d2121  8b710c               mov esi, dword ptr [ecx + 0xc]
// 006d2124  8b06                 mov eax, dword ptr [esi]
// 006d2126  8b10                 mov edx, dword ptr [eax]
// 006d2128  6a00                 push 0
// 006d212a  8bce                 mov ecx, esi
// 006d212c  ffd2                 call edx
// 006d212e  56                   push esi
// 006d212f  6a00                 push 0
// 006d2131  ff15ac22b200         call dword ptr [0xb222ac]
// 006d2137  50                   push eax
// 006d2138  ff15a822b200         call dword ptr [0xb222a8]
// 006d213e  5e                   pop esi
// 006d213f  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
extern void* (__cdecl *GetProcessHeapPtr)();
extern int (__stdcall *HeapFreePtr)(void*, unsigned long, void*);

struct S {
    int pad0[3];
    void* p;

    void f();
};

void S::f()
{
    void* q = p;
    void** vtable = *(void***)q;
    void (__thiscall *destroy)(void*, int) =
        (void (__thiscall *)(void*, int))vtable[0];
    destroy(q, 0);
    HeapFreePtr(GetProcessHeapPtr(), 0, q);
}
}