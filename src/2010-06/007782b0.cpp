// from server: 78% by atomic.potato
struct S
{
    int value;
    S *f(int);
};

S *S::f(int a)
{
    value = 0xA20A34;
    if (a & 1)
        f(0);
    return this;
}
