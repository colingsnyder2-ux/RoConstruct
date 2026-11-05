// from server: 29% by atomic.potato
struct S
{
    void *Get(void *);
    int f(void *);
};

void *S::Get(void *p)
{
    return p;
}

int S::f(void *p)
{
    void *v = Get((char *)p + 4);
    void *q = *(void **)v;
    return ((int (__thiscall *)(S *, void *))0x76a190)(this, &q);
}
