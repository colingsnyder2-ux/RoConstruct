// from server: 94% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
};

extern S *G1_func_0090fe70();
extern void *G1_func_00B221B8;
extern void *G1_func_00B221B4;

int __cdecl f(int *value)
{
    S *p = G1_func_0090fe70();
    EnterCriticalSection(p);
    *value = *(int *)((char *)p + 24);
    *(int *)((char *)p + 24) = (int)value;
    LeaveCriticalSection(p);
    return 0;
}
