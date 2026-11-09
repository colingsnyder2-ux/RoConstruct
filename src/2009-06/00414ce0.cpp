// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct pool_type {
    CRITICAL_SECTION mtx;
    void* first;
    static pool_type& instance();
};
extern long g_count;
void poolFree(void* p)
{
    pool_type& pt = pool_type::instance();
    EnterCriticalSection(&pt.mtx);
    *(void**)p = pt.first;
    pt.first = p;
    LeaveCriticalSection(&pt.mtx);
    InterlockedDecrement(&g_count);
}
