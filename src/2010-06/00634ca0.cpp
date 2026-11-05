// from server: 17% by atomic.potato
struct S
{
    int f();
    int unused;
    int value;
    int count;
};

int S::f()
{
    if (count > 0)
        return value / count;
    return 0;
}
