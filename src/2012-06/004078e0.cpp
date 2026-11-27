// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Mod { virtual void a(); virtual void b(); virtual void Unlock(); };
Mod* g_mod;
struct P0 { virtual void a0(); };
struct P1 { virtual void a1(); int x; };
struct P2 { virtual void a2(); int y; };
struct P3 { virtual void a3(); };
struct B : P0, P1, P2, P3 { long ref; ~B() throw(); };
struct D : B { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual ~D() throw(); };
D::~D() throw() { ref = -(2147483647L / 2); g_mod->Unlock(); }
