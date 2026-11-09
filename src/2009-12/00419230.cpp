// from server: 66% by atomic.potato
struct S
{
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    int *p = (int *)(a - 204);
    int *q = (int *)p[8];
    int (**v)(int, int, int) = (int (**)(int, int, int))q[0];
    return v[112](c, b, a);
}
