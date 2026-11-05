// from server: 27% by atomic.potato
struct S
{
    virtual void f();
    void g();
};

void S::g()
{
    f();
}
