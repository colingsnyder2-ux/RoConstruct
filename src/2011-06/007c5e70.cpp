// from server: 18% by atomic.potato
struct S
{
    int f();
    int a;
    int b;
};

int S::f()
{
    volatile int x = b;
    volatile int y = a;
    return (x - y) / 20;
}
