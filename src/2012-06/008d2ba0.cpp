// from server: 59% by atomic.potato
struct S
{
    void __cdecl f(int, float);
};

void S::f(int a, float b)
{
    if (*((int *)((char *)a + 0x10)) != 0)
    {
        struct V
        {
            int (**p)(V *, int, float);
        };

        V *v = (V *)((char *)a + 8);
        v->p[0](v, a, b);
    }
}
