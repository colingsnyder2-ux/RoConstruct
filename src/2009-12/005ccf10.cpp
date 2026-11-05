// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    struct VTable
    {
        void *unused[4];
        void (__thiscall *release)(void *, int);
    };

    void *p = *(void **)((char *)this + 0x0c);
    if (p != 0)
        ((VTable *)*(void **)p)->release(p, 1);
}
