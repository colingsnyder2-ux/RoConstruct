// from server: 28% by atomic.potato
struct S
{
    int f();
    void *vtable;
    void *field10;
};

int S::f()
{
    typedef int (__thiscall *Fn)(void *);
    void *p = *(void **)((char *)this + 0x10);
    void *q = *(void **)p;
    return ((Fn)*(void **)((char *)q + 0x7c))(p);
}
