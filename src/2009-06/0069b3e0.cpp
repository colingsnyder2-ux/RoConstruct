// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P0 { virtual ~P0(); char pad[0x10]; };
struct P1 { virtual void f1(); };
struct P2 { virtual void f2(); int a; };
struct P3 { virtual void f3(); char pad[0x68]; };
struct P4 { virtual void f4(); char pad[0x6c]; };
struct P5 { virtual void f5(); char pad[0xc]; };
struct P6 { virtual void f6(); char pad[0xc]; };
struct P7 { virtual void f7(); };
struct B : P0, P1, P2, P3, P4, P5, P6, P7 { virtual ~B(); };
struct D : B { D(); virtual ~D() {} };
D::D() {}
