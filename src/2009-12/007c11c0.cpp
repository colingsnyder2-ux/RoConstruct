// from server: 100% by atomic.potato
struct S
{
    void f(int a, int b);
    int pad[4];
    int x;
    int y;
};

void S::f(int a, int b)
{
    if (a == 0)
        x = b;
    else
        y = b;
}
