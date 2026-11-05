// from server: 89% by atomic.potato
struct S
{
    virtual void f(int);
    unsigned char pad[0x280];
    unsigned char flag;
    void g(int);
};

void S::g(int value)
{
    if (!flag)
    {
        f(value);
        flag = 1;
    }
}
