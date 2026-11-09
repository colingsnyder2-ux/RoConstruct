// from server: 100% by atomic.potato
struct S
{
    struct V
    {
        int (**vtable)();
    };

    char pad[12];
    V* p;
    void f();
};

void S::f()
{
    V* p = this->p;
    if (p)
        ((void (__thiscall *)(V*, int))p->vtable[1])(p, 1);
}
