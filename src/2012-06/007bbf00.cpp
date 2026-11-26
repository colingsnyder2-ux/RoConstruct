// from server: 90% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
struct CRITICAL_SECTION { char b[24]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern void* __cdecl allocNew();
extern char g_flag;
extern void __cdecl onThrow();
struct Pool { CRITICAL_SECTION cs; void* head;
    void* poolMalloc() { if (head) { void*& l = head; void* r = l; l = *(void**)r; return r; } return allocNew(); }
};
Pool* __cdecl getPool();
void* __cdecl f()
{
    Pool* p = getPool();
    EnterCriticalSection(&p->cs);
    void* r = p->poolMalloc();
    LeaveCriticalSection(&p->cs);
    if (!r) {
        if (g_flag)
            onThrow();
        throw std::bad_alloc();
    }
    return r;
}
