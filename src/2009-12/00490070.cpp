// from server: 84% by atomic.potato
struct S
{
    int f();
    int pad[33];
};

int S::f()
{
    struct VTable
    {
        int unused[6];
        int (*get)();
    };

    struct Base
    {
        VTable *vtable;
    };

    Base *base = *(Base **)((char *)this + 0x84);
    return base->vtable->get();
}
