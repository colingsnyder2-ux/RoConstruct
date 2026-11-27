// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X;
struct RCP {
    X* p;
    RCP() : p(0) {}
    RCP(const RCP& r) : p(0) { setPointer(r.p); }
    ~RCP();
    void setPointer(X* q);
};
struct C {
    virtual void f();
    RCP a;
    int b;
    C(int x, const RCP& r);
    void init(int);
};
C::C(int x, const RCP& r) : a(r), b(0) { init(x); }
