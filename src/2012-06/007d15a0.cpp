// from server: 80% by atomic.potato
struct S
{
    void f();
    int a;
    int b;
    int c[6];
    int d[16];
};

void S::f()
{
    a = 0xbbfeac;
    b = 0xbbfea0;
    c[4] = 0xbbfe94;
    c[5] = 0xbbfe88;
    d[0] = 0xbbfe80;
}
