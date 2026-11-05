// from server: 57% by atomic.potato
struct S
{
    char pad[0xa4];
    void f();
    void g(int);
};

void S::f()
{
    f();
    g(0);
}
