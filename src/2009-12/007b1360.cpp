// from server: 11% by atomic.potato
struct S
{
    int f();
    int value;
};

int S::f()
{
    while (value != 0)
        value = 0;
    return 0;
}
