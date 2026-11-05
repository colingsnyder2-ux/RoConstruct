// from server: 96% by atomic.potato
extern "C" void __cdecl f90f6f0(void *, unsigned int);
extern "C" void __cdecl f982114(void *);

struct S
{
    void f();
    void *pad0;
    void *pad1;
    void *value;
};

void S::f()
{
    void *p = value;
    if (p)
    {
        f90f6f0(p, *(unsigned int *)((char *)p + 12));
        f982114(p);
    }
}
