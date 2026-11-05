// from server: 100% by atomic.potato
struct S
{
    void g();
    void f();
    char pad[0x48];
    char flag;
};

void S::f()
{
    if (flag)
    {
        g();
        flag = 0;
    }
}
