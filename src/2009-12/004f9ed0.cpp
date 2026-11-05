// from server: 50% by atomic.potato
struct S
{
    int f(void *);
    int **v;
};

extern "C" int __cdecl call_4f8ec0(int *, int);

int S::f(void *a)
{
    int *p = (int *)v[7];
    int (*q)(int *, void *) = (int (*)(int *, void *))p[3];
    int x = q(p, a);
    return call_4f8ec0((int *)0, x);
}
