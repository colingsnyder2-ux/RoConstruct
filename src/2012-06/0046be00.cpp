// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct P0 { virtual void a(); };
struct P1 { virtual void b(); char pad[0x10]; };
struct P2 { virtual void c(); };
struct P3 { virtual void d(); char pad[0x60]; };
struct B : P0, P1, P2, P3 { B(); virtual ~B(); };
struct D : B {
    double x;
    std::string s;
    D();
    virtual void a(); virtual void b(); virtual void c(); virtual void d();
};
D::D() : x(0.0) {}
