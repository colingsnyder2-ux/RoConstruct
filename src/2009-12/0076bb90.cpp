// from server: 31% by atomic.potato
struct S
{
    typedef void (__thiscall *F)(void *, void *);

    void __cdecl f(void *, void *);
};

void S::f(void *a, void *b)
{
    F fn = *(F *)a;
    void *ecx = *(void **)((char *)a + 4);
    ecx = (char *)ecx + *(int *)((char *)a + 8);
    void *arg = *(void **)((char *)a + 12);
    fn(ecx, b);
}
