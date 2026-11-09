// from server: 69% by atomic.potato
struct S
{
    int a;
    int b;
    int c[4];
    int d;
    int e[24];
    void f();
};

extern "C" void target();

void S::f()
{
    a = 0xbaad74;
    b = 0xbaad6c;
    c[2] = 0xbaad60;
    d = 0xbaad54;
    e[20] = 0xbaad28;
    target();
}
