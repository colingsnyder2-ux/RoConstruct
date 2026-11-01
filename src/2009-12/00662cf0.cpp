// from server: 100% by atomic.potato
struct S
{
    int f(const S *value);
};

int S::f(const S *value)
{
    return this != value;
}
