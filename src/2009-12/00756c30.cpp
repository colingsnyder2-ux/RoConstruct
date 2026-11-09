// from server: 36% by atomic.potato
struct S
{
    int (*callback)(int);
    int value;
    S *f(int);
};

S *S::f(int p)
{
    int offset = p ? p - 28 : 0;
    int result = callback(value + offset);
    return this;
}
