// from server: 100% by atomic.potato
struct S
{
    struct VTable
    {
        void *p0;
        void *p1;
        void *p2;
        void *p3;
        void *p4;
        void *p5;
    };

    VTable *vtable;
    char f();
};

char S::f()
{
    int i = 0;
    while (i < 2)
    {
        S *p = ((S *(__thiscall *)(S *, int))vtable->p5)(this, i);
        if (p != 0 && *(S **)((char *)p + 0x24) == this)
            return 1;
        ++i;
    }
    return 0;
}
