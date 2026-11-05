// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __stdcall release_00b16120(void*);
extern "C" void* _InterlockedExchange(void* volatile* target, void* value);
extern void* g_pool_00b16120;

void func_00b16120()
{
    void* p = _InterlockedExchange((void* volatile*)&g_pool_00b16120, 0);
    if (p)
        release_00b16120(p);
}
