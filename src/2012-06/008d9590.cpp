// from server: 86% by atomic.potato
struct S
{
    void f(int, float, float);
    void g(int, float, float);
};

void S::f(int a, float b, float c)
{
    g(a, b, c);
}
