// from server: 96% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P0 { virtual void f0(); };
struct P1 { virtual void f1(); int pad[4]; };
struct P2 { virtual void f2(); };
struct P3 { virtual void f3(); int pad[2]; int x[(0x88 - 0x28) / 4]; };
struct Base : P0, P1, P2, P3 { Base(); ~Base(); };
struct M { M(); ~M(); int pad[4]; };
struct Y { int a, b; Y() : a(0), b(0) {} ~Y(); };
struct D : Base {
    Y y; char pad90[5]; bool f95; M m;
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    D();
};
D::D() : Base(), f95(false) {}
