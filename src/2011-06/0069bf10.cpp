// from server: 35% by atomic.potato
struct S
{
    char pad[144];
    double value;
    void f(double);
};

void S::f(double x)
{
    value = x;
}
