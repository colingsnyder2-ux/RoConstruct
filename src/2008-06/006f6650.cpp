// from server: 100% by atomic.potato
struct S {
    void *f(void *);
};

extern "C" void *__cdecl sym();

void *S::f(void *a)
{
    void *p = sym();
    ((void *(__thiscall *)(void *, void *, void *))(*(void ***)p)[0xe0 / 4])(p, this, a);
    return p;
}
