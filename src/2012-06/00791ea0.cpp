// from server: 83% by atomic.potato
struct S {
    int a;
    int b;
    int c[4];
    int d;
    void f();
};

void S::f()
{
    a = 0x00bb2544;
    b = 0x00bb2538;
    c[2] = 0x00bb252c;
    d = 0x00bb2520;
}
