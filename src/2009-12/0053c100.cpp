// from server: 71% by atomic.potato
struct S
{
    int a0;
    int a4;
    int a8;
    int ac;
    int a10;
    int a14;

    void f(int x, int y);
};

void S::f(int x, int y)
{
    a8 = 0;
    ac = 0;
    a10 = x;
    a0 = 0x9bd2cc;
    a14 = y;
}
