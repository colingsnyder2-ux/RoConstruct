// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P0 { virtual void a(); };
struct P1 { virtual void b(); char pad[0x48]; };
struct P2 { virtual void c(); char pad[0x5c - 0x54]; };
struct B : P0, P1, P2 { virtual ~B(); };
struct D : B {
    virtual ~D() {}
    virtual void a(); virtual void b(); virtual void c();
};
D* mk() { return new D; }
