// from server: 100% by atomic.potato
struct S;

struct X {
    void Detach(S* owner);
    void Attach(S* owner);
};

struct S {
    char pad[0xa0];
    X* m_field;
    X* GetNext();
    void f();
};

void S::f()
{
    X* nv = GetNext();
    X* old = m_field;
    if (old == nv)
        return;
    if (old != 0) {
        m_field = 0;
        old->Detach(this);
    }
    m_field = nv;
    if (nv != 0)
        nv->Attach(this);
}
