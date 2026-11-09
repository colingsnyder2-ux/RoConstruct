// from server: 40% by atomic.potato
struct S
{
    typedef void (__thiscall *F)(S *, int);
    F f;
    int a;
    int b;
    void g();
};

void S::g()
{
    f(this, b);
}
