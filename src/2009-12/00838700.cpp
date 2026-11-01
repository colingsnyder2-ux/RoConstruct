// from server: 25% by atomic.potato
struct S
{
    int f(int);
    int IsLayoutRTL();
};

int S::IsLayoutRTL()
{
    return 0;
}

int S::f(int value)
{
    if (IsLayoutRTL())
    {
        if (value == 0)
            return 1;
        if (value == 1)
            return 0;
    }
    return 0;
}
