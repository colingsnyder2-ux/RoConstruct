// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct S;
void adv(double** it, S* c, int n);
struct S {
    S* p0;
    int p4;
    double* p8;
    S* get() const;
    int count() const;
    S& f();
};
S& S::f() {
    adv(&p8, get()->get(), get()->count());
    return *this;
}
