// from server: 91% by atomic.potato
struct XDocHostUIHandler
{
    void __stdcall f(void *, void *, void *);
};

void __stdcall XDocHostUIHandler::f(void *a1, void *a2, void *a3)
{
    struct T
    {
        void **vtable;
    };

    T *p = *(T **)((char *)a1 - 0xcc);
    T *q = *(T **)((char *)p + 0x20);
    typedef void (__thiscall *Fn)(T *, void *, void *);
    Fn fn = (Fn)(q->vtable[0x1c4 / 4]);
    fn(q, a3, a2);
}
