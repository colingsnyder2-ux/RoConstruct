// from server: 60% by atomic.potato
struct S
{
    int f();
    char padding[640];
    int value;
};

int S::f()
{
    if (value == 0)
        return 0;
    if (value == 1)
        return 2;
    if (value == 2)
        return 1;
    return 1;
}
