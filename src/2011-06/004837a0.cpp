// from server: 100% by atomic.potato
struct S
{
    void f();
    void g();
    void h(int);
    void k();
};

void S::f()
{
    g();
    h(1);
    k();
}
