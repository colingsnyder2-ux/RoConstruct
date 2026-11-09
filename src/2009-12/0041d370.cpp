// from server: 100% by atomic.potato
struct S
{
    void f(S *a, int *b);
};

void S::f(S *a, int *b)
{
    void **p = *(void ***)((char *)a + 0x5c);
    void (__thiscall *fn)(void *, int) =
        (void (__thiscall *)(void *, int))(*(void **)((char *)*p + 0xc));
    fn(p, *(int *)((char *)a + 0xc));
    *b = 0;
}
