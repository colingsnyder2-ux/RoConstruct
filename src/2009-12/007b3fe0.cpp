// from server: 93% by atomic.potato
extern "C" int __cdecl sub_7b3ef0();
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" long __stdcall InterlockedDecrement(long *);
extern "C" void __stdcall LeaveCriticalSection(void *);

extern "C" void (__stdcall *p_98b204)(void *);
extern "C" void (__stdcall *p_98b200)(void *);
extern "C" void (__stdcall *p_98b208)(const char *);

struct S
{
};

int __cdecl f(int *p)
{
    int *q = (int *)sub_7b3ef0();
    EnterCriticalSection(q);
    *p = q[6];
    q[6] = (int)p;
    LeaveCriticalSection(q);
    p_98b208((const char *)0xb7b42c);
    return 0;
}
