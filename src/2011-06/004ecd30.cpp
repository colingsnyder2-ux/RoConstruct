// from server: 100% by atomic.potato
struct S
{
    void f(int);
    char padding[8];
    int value;
};

void S::f(int x)
{
    value += x * 8;
}
