// from server: 100% by atomic.potato
struct S
{
    void f();
    void g();
    unsigned char pad[0x58];
    unsigned char flag;
};

void S::f()
{
    if (flag)
    {
        g();
        flag = 0;
    }
}
