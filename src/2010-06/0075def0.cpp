// from server: 100% by atomic.potato
struct S
{
    int *v;
    void *f();
};

void *S::f()
{
    int i = 0;
    void *p;
    do
    {
        p = ((void *(__thiscall *)(S *, int))v[5])(this, i);
        if (p && *((S **) ((char *)p + 0x24)) == this)
            return p;
        ++i;
    } while (i < 2);
    return 0;
}
