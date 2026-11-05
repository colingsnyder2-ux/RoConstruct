// from server: 100% by tester
struct Inner {
    virtual void v();
};

struct S {
    char pad[40];
    Inner* m_p;
    void f();
};

void S::f()
{
    Inner* p = m_p;
    p->v();
}
