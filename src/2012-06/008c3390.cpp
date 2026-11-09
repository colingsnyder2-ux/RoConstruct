// from server: 83% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int value;
    int g;

    void f();
};

void S::f()
{
    a = 0xbe612c;
    b = 0xbe6124;
    e = 0xbe6118;
    value = 0xbe610c;
}
