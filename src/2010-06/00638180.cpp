// from server: 15% by atomic.potato
struct P_func_00679420 { void g(); };
struct S_func_00679420 {
    char pad[244];
    P_func_00679420* m_p;
    void f();
};
void S_func_00679420::f()
{
    m_p->g();
}

struct Inner {
    void f();
};

struct Outer {
    char pad0[0x168];
    Inner* m_p;
    Outer* f(Outer* a, Outer* b);
};

void Inner::f() {}

Outer* Outer::f(Outer* a, Outer* b)
{
    if (this == b) {
        a->m_p->f();
        return a;
    }
    Inner* p1 = this->m_p;
    p1->f();
    Inner* p2 = b->m_p;
    p2->f();
    Inner tmp;
    tmp.f();
    Inner tmp2;
    tmp2.f();
    Outer* r = a->f(a, b);
    r->m_p->f();
    return r;
}
