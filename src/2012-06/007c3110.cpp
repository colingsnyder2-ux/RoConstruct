// from server: 80% by atomic.potato
struct S
{
    void f(int);
    void g(int);
    void h();
    unsigned char pad[0x31c];
    unsigned char flag;
};

void S::f(int x)
{
    if (!flag)
    {
        g(x);
        flag = 1;
        h();
    }
}
