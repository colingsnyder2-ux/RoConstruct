// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P0 { virtual void f0(); };
struct P1 { virtual void f1(); int pad[4]; };
struct P2 { virtual void f2(); };
struct P3 { virtual void f3(); int pad[2]; int x[(0x80 - 0x28) / 4]; };
struct P4 { virtual void f4(); };
struct Base : P0, P1, P2, P3, P4 { Base(); ~Base(); };
struct D : Base {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    D(); void init();
};
D::D() : Base() { init(); }
