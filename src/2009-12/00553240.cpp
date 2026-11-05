// from server: 100% by atomic.potato
struct S
{
    void f(double, int, int);
    char padding[0x12f8];
    double a;
    int b;
    int c;
};

void S::f(double x, int y, int z)
{
    a = x;
    b = y;
    c = z;
}
