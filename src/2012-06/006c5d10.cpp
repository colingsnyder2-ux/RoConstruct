// from server: 37% by atomic.potato
struct S
{
    void *field28;
    void f(void *, void *);
};

typedef void (__thiscall *F)(void *, void *);

extern "C" void __cdecl sym(void *, void *);

void S::f(void *a, void *b)
{
    void *p;
    F fn;

    p = *(void **)((char *)this + 0x28);
    fn = *(F *)((char *)p + 8);
    fn(*(void **)p, &p);
    p = b;
    sym(&p, p);
}
