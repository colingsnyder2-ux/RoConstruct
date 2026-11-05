// from server: 47% by atomic.potato
typedef void *(__thiscall *Callback)(void *, void *);

extern "C" void * __cdecl sub_00632fd0(void *, void *);

struct S
{
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    void *v;
    void *p = *(void **)((char *)this + 0x1c);
    v = sub_00632fd0(a, &v);
    Callback fn = *(Callback *)((char *)*(void **)p + 0x0c);
    fn(p, b);
    return 0;
}
