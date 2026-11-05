// from server: 94% by atomic.potato
struct S
{
};

extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

extern S *G1_func_0090f3e0();

int __cdecl f(int *p)
{
    S *q = G1_func_0090f3e0();
    EnterCriticalSection(q);
    *p = *(int *)((char *)q + 0x18);
    *(int *)((char *)q + 0x18) = (int)p;
    LeaveCriticalSection(q);
    return 0;
}
