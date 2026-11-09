// from server: 100% by atomic.potato
struct S {
    void __stdcall f();
};

void __stdcall S::f()
{
    struct T {
        void *vtable;
    };

    T *p = *(T **)((char *)this - 0xcc);
    T *q = *(T **)((char *)p + 0x20);
    typedef void (__thiscall *Fn)(T *);
    Fn fn = (Fn)(*(void **)((char *)*(void **)q + 0x1ac));
    fn(q);
}
