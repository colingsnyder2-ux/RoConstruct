// from server: 61% by atomic.potato
struct S
{
    void f();
    void *v0;
    char pad[80];
    void *v58;
};

void S::f()
{
    *(int *)this = 0x00b5c658;
    *(int *)((char *)this + 0x54) = 0x00b5c650;
    *(int *)((char *)this + 0x54) = 0x00b43e60;

    void *p = *(void **)((char *)this + 0x58);
    if (p)
    {
        void **vtable = *(void ***)p;
        typedef void (__thiscall *Fn)(void *);
        ((Fn)vtable[4])(p);
    }

    ((void (__thiscall *)(S *))0x0047dbb0)(this);
}
