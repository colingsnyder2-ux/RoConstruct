// from server: 73% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*((int *)((char *)this + 0x24c)) != 0)
    {
        struct VTable
        {
            int (**vtable)();
        };

        VTable *p = (VTable *)*((int *)((char *)this + 0x250));
        int result = p->vtable[10]();
        return result == 0x0d;
    }

    return 1;
}
