// from server: 89% by atomic.potato
typedef unsigned char byte;

struct S
{
    int f(byte flags);
};

typedef void (__thiscall *DestroyFn)(void *);

extern "C" void DestroyObject(void *);

extern "C" void __cdecl ReleaseObject(void *);

int S::f(byte flags)
{
    S *p = (S *)((char *)this - 0x54);
    DestroyObject(p);
    if (flags & 1)
        ReleaseObject(p);
    return (int)p;
}
