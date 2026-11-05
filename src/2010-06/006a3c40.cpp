// from server: 100% by atomic.potato
struct S
{
    void f();
    void g();
    unsigned char padding[0x48];
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
