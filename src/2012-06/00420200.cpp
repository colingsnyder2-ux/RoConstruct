// from server: 100% by atomic.potato
extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(void *);
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(void *);

struct S
{
    int f();
};

int S::f()
{
    void *p = (void *)((char *)this + 0x144);
    EnterCriticalSection(p);
    *(int *)((char *)this + 0x160) = 0;
    *(int *)((char *)this + 0x164) = 0;
    LeaveCriticalSection(p);
    return 0;
}
