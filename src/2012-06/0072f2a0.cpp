// from server: 17% by atomic.potato
struct S
{
    int f(int);
    int g(int *);
};

struct T
{
    int f(int);
};

int S::g(int *x)
{
    return 0;
}

int T::f(int x)
{
    return 0;
}

int S::f(int x)
{
    return g(&x);
}
