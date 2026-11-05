// from server: 48% by atomic.potato
struct S {
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    char *p = *(char **)((char *)this + 0x1c);
    p += 0x10;
    void *v = 0;
    extern void *__cdecl g(void *, void *);
    v = g(b, &v);
    typedef void (__thiscall *T)(void *, void *, void *);
    T q = *(T *)p;
    q(*(void **)((char *)this + 0x1c), a, v);
}
