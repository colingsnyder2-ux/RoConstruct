// from server: 20% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    volatile int x = 0;
    if (x)
        return x + 1;
    return 0;
}
