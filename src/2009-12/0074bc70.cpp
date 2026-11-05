// from server: 64% by atomic.potato
struct S
{
    void __cdecl f(float, float);
};

void S::f(float a, float b)
{
    void **p = (void **)this;
    typedef void (__thiscall *Fn)(void *, float, float);
    Fn fn = (Fn)p[0];
    fn((void *)p[1], a, b);
}
