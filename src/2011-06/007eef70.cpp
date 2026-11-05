// from server: 84% by atomic.potato
struct S
{
    void f(int);
    void g(int);
};

void S::f(int value)
{
    f(value);
    g(value);
}
