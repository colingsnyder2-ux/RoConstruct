// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
struct P0 { virtual void a0(); };
struct P1 { virtual void a1(); char p[0x10]; };
struct P2 { virtual void a2(); };
struct P3 { virtual void a3(); };
struct B : P0, P1, P2, P3 { char pad[0x61 - 0x20]; bool f61; char pad2[0x80 - 0x62]; B(); ~B(); };
struct M { M(); };
static volatile long g_n;
struct D : B { bool f80; long id; M m; D(); virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); };
D::D() : B(), f80(false), id(_InterlockedIncrement(&g_n)), m() { f61 = true; }
