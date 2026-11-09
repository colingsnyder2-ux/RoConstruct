// from server: 83% by atomic.potato
extern "C" void __cdecl sub_532fb0(void *, void *);
extern "C" void __cdecl sub_53bca0(void *);

struct S
{
    void __cdecl f(void *, void *);
};

void __cdecl S::f(void *a, void *b)
{
    char x[8];
    sub_532fb0(a, x);
    if (*((int *)((char *)b + 4)) != 0)
        sub_53bca0(x);
}
