// from server: 90% by atomic.potato
struct S {
    virtual void f() = 0;
    S *g(int);
};

S *S::g(int)
{
    f();
    return this;
}
