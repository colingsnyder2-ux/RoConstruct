// from server: 100% by tester
struct S
{
    void f();
    void g();
    unsigned char padding[0x48];
};

void S::f()
{
    if (padding[0x48])
    {
        g();
        padding[0x48] = 0;
    }
}
