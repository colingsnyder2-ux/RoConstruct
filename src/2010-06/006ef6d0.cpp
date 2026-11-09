// from server: 100% by atomic.potato
struct S {
    char padding[0xf4];
    int a;
    int b;
    void f(int, int);
};

void S::f(int x, int y)
{
    a = x;
    b = y;
}
