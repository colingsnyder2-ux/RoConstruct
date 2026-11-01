// from server: 100% by colin
struct Inner {
    virtual void v();
};

struct S {
    char pad[24];
    Inner* m_p;
    void f();
};

void S::f()
{
    Inner* p = m_p;
    p->v();
}
