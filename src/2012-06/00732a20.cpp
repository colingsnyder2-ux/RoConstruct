// from server: 47% by atomic.potato
struct S
{
    int f(void *);
    int (**p)(int);
    int q;
};

int S::f(void *x)
{
    int a = x ? ((int *)x - 7)[0] : 0;
    int v = p[0](q + a);
    return *(int *)x = v, (int)x;
}
