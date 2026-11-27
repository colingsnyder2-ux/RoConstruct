// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct X;
X *GetDescriptor();
struct VT0 { void (*manager)(void *, void *, int); };
struct VT1 {
    void *reserved;
    void (*destroy)(void *);
    void (*clone)(const void *, void *);
};
struct B { int d[4]; };
struct L {
    VT1 *vt;
    char buf[0x3c];
    L(const B &);
    L(const L &o)
    {
        vt = 0;
        if (o.vt)
            o.vt->clone(o.buf, buf);
        vt = o.vt;
    }
    ~L()
    {
        if (vt)
            vt->destroy(buf);
    }
};
struct T {
    X *p;
    L l;
    T(X *p_, const B &b) : p(p_), l(b) {}
};
struct A {
    VT0 *vt;
    int pad;
    char buf[0x18];
    void invoke(T);
    ~A()
    {
        if (vt) {
            void (*m)(void *, void *, int) = vt->manager;
            if (m)
                m(buf, buf, 2);
        }
    }
};
void BoundCall(A a, B b)
{
    T t(GetDescriptor(), b);
    a.invoke(t);
}
