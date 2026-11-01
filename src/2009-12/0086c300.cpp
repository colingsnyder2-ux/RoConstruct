// from server: 91% by atomic.potato
struct S
{
    void f(void *a, void *b);
};

extern "C" void *__cdecl fn(void);

void S::f(void *a, void *b)
{
    void *p = fn();
    void (__thiscall *g)(void *, void *, void *) =
        *(void (__thiscall **)(void *, void *, void *))(*(unsigned char **)p + 0x18);
    g(p, this, b);
}
