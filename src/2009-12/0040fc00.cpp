// from server: 50% by atomic.potato
struct S
{
    void **v;
    int a;
    int b;
    int c;
    void *p;

    void f();
};

typedef void (__thiscall *F)(void *);

extern "C" void __cdecl target(void *);

void S::f()
{
    v = (void **)0x9a1bbc;
    *(void ***)((char *)this + 0xc) = (void **)0x9a1bb4;
    *(void ***)((char *)this + 0xc) = (void **)0x99fdd8;

    if (p != 0)
    {
        F fn = (F)(*(void ***)p)[4];
        fn(p);
    }

    target(this);
}
