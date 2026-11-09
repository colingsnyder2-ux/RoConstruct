// from server: 67% by atomic.potato
extern "C" int __cdecl sub_006edfb0();
extern "C" int __stdcall EnterCriticalSection(void *);
extern "C" long __stdcall InterlockedDecrement(long *);
extern "C" int __stdcall LeaveCriticalSection(void *);

struct S
{
    int f(int *);
};

int S::f(int *p)
{
    int esi = sub_006edfb0();
    EnterCriticalSection((void *)0x98b204);
    int value = *(int *)(esi + 0x18);
    *p = value;
    *(int *)(esi + 0x18) = (int)p;
    LeaveCriticalSection((void *)0x98b200);
    InterlockedDecrement((long *)0x00b7b434);
    return 0;
}
