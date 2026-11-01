// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct X;
struct A { void g(); };
struct R { R(X* x); ~R(); void* p; };
struct M { void h(R& r); };
struct X {
    int a;
    M* m;
    bool cond();
    A* getA();
    void f();
};
void X::f()
{
    if (cond()) {
        getA()->g();
        R r(this);
        m->h(r);
    }
}
