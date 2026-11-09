// from server: 74% by atomic.potato
struct S
{
    int f(const S& other) const;
    int a;
    int b;
};

int S::f(const S& other) const
{
    if (a == other.a)
    {
        if (b == other.b)
            return 0;
    }
    return 1;
}
