// from server: 35% by atomic.potato
struct S
{
    S * __cdecl f(int);
};

S *S::f(int value)
{
    int zero = 0;
    char flag = 0;
    f(zero);
    return this;
}
