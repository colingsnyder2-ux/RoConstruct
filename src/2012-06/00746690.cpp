// from server: 77% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int value)
{
    int bits;
    if (value < 0 || value > 2)
        return ((*(volatile int*)this) & 0) != 0;
    bits = *(volatile int*)this;
    return (bits & (1 << value)) != 0;
}
