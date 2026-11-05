// from server: 55% by atomic.potato
struct S
{
    int f(int a, int b);
};

int S::f(int a, int b)
{
    int (*p)(int, int) = *(int (**)(int, int))((char *)this + 12);
    return p(*(int *)((char *)this + 16), a);
}
