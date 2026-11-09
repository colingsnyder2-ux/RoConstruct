// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Slot {
    char pad0[0xc];
    void (__stdcall *fn)(void*, int, int, int);
    char pad10[0x4];
    int *refcount;
    char pad18[0x4];
    int arg18;
};

struct Callable {
    void invoke(int a, int b, int c);
};

void Callable::invoke(int a, int b, int c)
{
    Slot *s = (Slot *)this;
    int *rc = s->refcount;
    int v = s->arg18;
    if (rc) {
        _InterlockedExchangeAdd((volatile long *)((char *)rc + 8), 1);
    }
    s->fn((void *)rc, v, a, b);
}
