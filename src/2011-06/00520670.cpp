// from server: 100% by atomic.potato
struct S
{
    int pad;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    int f();
};

int S::f()
{
    unsigned int x = a;
    unsigned int y = b;
    if (x <= y)
        return (int)(y - x);
    return (int)(c - x + y);
}
