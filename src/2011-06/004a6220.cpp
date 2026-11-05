// from server: 66% by atomic.potato
struct S
{
    int *p48;
    int f();
};

int S::f()
{
    if (p48 == 0)
        return 0;
    return (p48[2] - p48[1]) >> 3;
}
