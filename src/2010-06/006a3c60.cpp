// from server: 100% by atomic.potato
struct S
{
    void f();
    void g();
    unsigned char padding[0x58];
};

void S::f()
{
    if (padding[0x58])
    {
        g();
        padding[0x58] = 0;
    }
}
