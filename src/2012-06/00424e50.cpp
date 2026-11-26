// from server: 100% by Xemicl
// roc 2012-06 00424e50  unit: RBX::FunctionMarshaller  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00424e50
//
// 00424e50  33c0                 xor eax, eax
// 00424e52  83c10c               add ecx, 0xc
// 00424e55  8701                 xchg dword ptr [ecx], eax
// 00424e57  85c0                 test eax, eax
// 00424e59  7407                 je 0x424e62
// 00424e5b  50                   push eax
// 00424e5c  ff15e821b200         call dword ptr [0xb221e8]
// 00424e62  c3                   ret 
// copied from an identical function in another client (function ?ReleaseHandle@CSelectionTreeCtrl@@QAEXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct CSelectionTreeCtrl {
    char pad[0xc];
    void* handle;
    void ReleaseHandle();
};
void CSelectionTreeCtrl::ReleaseHandle() {
    void* old = (void*)_InterlockedExchange((long*)&handle, 0);
    if (old)
        CloseHandle(old);
}