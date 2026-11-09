// from server: 88% by tajop
struct X;

X *GetDescriptor();

struct VT0
{
    void (*manager)(void *, void *, int);
};

struct VT1
{
    void *reserved;
    void (*destroy)(void *);
    void (*clone)(const void *, void *);
};

struct B
{
    int d[4];
};

struct L
{
    VT1 *vt;
    char buf[0x3c];
    L(const B &);
    ~L()
    {
        if (vt)
            vt->destroy(buf);
    }
};

struct T
{
    X *p;
    VT1 *vt;
    char buf[0x3c];
    T(const T &);
    T(X *const &p_, const L &o) : p(p_)
    {
        vt = 0;
        if (o.vt)
            o.vt->clone(o.buf, buf);
        vt = o.vt;
    }
    ~T()
    {
        if (vt)
            vt->destroy(buf);
    }
};

struct A
{
    VT0 *vt;
    int pad;
    char buf[0x18];
    void invoke(T);
    ~A()
    {
        if (vt)
        {
            void (*m)(void *, void *, int) = vt->manager;
            if (m)
                m(buf, buf, 2);
        }
    }
};

void BoundCall(A a, B b)
{
    X *x = GetDescriptor();
    L l(b);
    a.invoke(T(x, l));
}
