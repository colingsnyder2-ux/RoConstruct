// from server: 100% by atomic.potato
struct S
{
    unsigned short a;
    unsigned short b;
    int c;
    int f(S* other);
};

int S::f(S* other)
{
    if (b == other->b && a == 2 && c == other->c)
        return 1;
    return 0;
}
