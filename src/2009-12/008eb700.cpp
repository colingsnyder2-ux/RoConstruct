// from server: 13% by atomic.potato
struct S
{
    int f(int);
    int g();
};

int S::f(int value)
{
    return 0;
}

int S::g()
{
    if (f(0) & 0x1000000)
    {
        if (f(1) & 0x40)
            return 1;
    }
    return 0;
}
