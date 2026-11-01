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
