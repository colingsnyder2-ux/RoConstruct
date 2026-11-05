// from server: 18% by atomic.potato
struct S
{
    int IsThemed();
    int f(int);
};

int S::IsThemed()
{
    return 0;
}

int S::f(int value)
{
    if (IsThemed())
        return 1;
    return value;
}
