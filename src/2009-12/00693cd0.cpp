// from server: 55% by atomic.potato
extern "C" void __cdecl sub_00693aa0(void *, void *);

struct S
{
    int f(void *, void *);
    char pad[28];
    int **vtable;
};

int S::f(void *a, void *b)
{
    int *p = *vtable;
    int *q = p + 4;
    void *x;
    sub_00693aa0(&x, a);
    return ((int (__thiscall *)(int *, void *, void *))q[0])(q, b, x);
}
