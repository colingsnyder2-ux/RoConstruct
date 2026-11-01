// from server: 86% by atomic.potato
struct S
{
    void f();
    void g();
};

void S::f()
{
    struct VTable
    {
        char pad[0x68];
        void (__thiscall *fn)(void *);
    };

    void *p = *(void **)((char *)this + 0xd4);
    VTable *v = *(VTable **)p;
    v->fn(p);
    g();
}
