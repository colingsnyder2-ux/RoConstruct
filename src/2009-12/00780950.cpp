// from server: 90% by atomic.potato
typedef int LONG;

extern "C" void* __cdecl func_0044f4e0();
extern "C" LONG __stdcall InterlockedDecrement(LONG*);
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

extern void* g_00b98834;

struct S_func_00780950
{
    void f(void**);
};

void S_func_00780950::f(void** out)
{
    void* p = func_0044f4e0();
    EnterCriticalSection(p);
    *out = *(void**)((char*)p + 24);
    *(void**)((char*)p + 24) = out;
    LeaveCriticalSection(p);
    InterlockedDecrement((LONG*)g_00b98834);
}
