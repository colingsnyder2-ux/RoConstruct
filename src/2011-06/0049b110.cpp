// from server: 57% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct V
    {
        int (**vtable)();
    };

    V* p = *(V**)((char*)this + 0x10c);
    if (p->vtable[3]())
        return p->vtable[9]();
    return 0;
}
