// from server: 100% by tester
struct S
{
    void f();
    void g();
    unsigned char padding[0x58];
    unsigned char active;
};

void S::f()
{
    if (active)
    {
        g();
        active = 0;
    }
}
