// from server: 37% by atomic.potato
struct S
{
    int f(int);
    int (*p)(int);
    int q;
};

int S::f(int value)
{
    int (*fn)(int) = (int (*)(int))p;
    if (value)
        return fn(q + value - 28);
    return fn(q);
}
