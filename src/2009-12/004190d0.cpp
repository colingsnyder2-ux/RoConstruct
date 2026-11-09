// from server: 70% by atomic.potato
struct S
{
    void f(void *, void *, void *, void *, void *);
};

void S::f(void *a, void *, void *, void *, void *e)
{
    struct V
    {
        void *vtable;
    };

    S *p = *(S **)((char *)a - 0xcc);
    V *q = *(V **)((char *)p + 0x20);
    typedef void (__thiscall *Fn)(void *, void *, void *, void *, void *);
    Fn fn = *(Fn *)((char *)q->vtable + 0x198);
    fn(q, e, e, e, e);
}
