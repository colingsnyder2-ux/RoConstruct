// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct Node { char pad[0x14]; long h; void cleanup(); };
struct L { Node* p; void f(); };
void L::f()
{
    Node* n = p;
    if (n) {
        void* old = (void*)_InterlockedExchange(&n->h, 0);
        if (old) CloseHandle(old);
        n->cleanup();
        delete n;
    }
}
