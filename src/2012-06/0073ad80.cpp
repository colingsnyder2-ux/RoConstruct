// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P0 { virtual void a0(); };
struct P1 { virtual void a1(); char p[0x10]; };
struct P2 { virtual void a2(); };
struct P3 { virtual void a3(); char q[0x28 - 0x20]; int f28; char q2[0x80 - 0x2c]; };
struct P4 { virtual void a4(); };
struct P5 { virtual void a5(); };
struct B : P0, P1, P2, P3, P4, P5 { B(); };
struct M { int x; M() {} ~M(); };
int mk();
int g_cnt;
struct D : B { M m; D(); virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); };
D::D() : B() { f28 = mk(); ++g_cnt; }
