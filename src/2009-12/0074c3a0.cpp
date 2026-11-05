// from server: 54% by atomic.potato
struct S
{
    void f(int);
};

extern "C" void __cdecl g(void *, int);

void S::f(int value)
{
    void *p = *(void **)this;
    if (p)
        g(p, value);
}
