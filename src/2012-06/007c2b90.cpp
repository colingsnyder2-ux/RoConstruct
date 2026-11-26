// from server: 89% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern bool g;
struct VB { void m(int); };
struct A { char pad[0x84]; };
struct D : A, virtual VB { void f(int a); };
void D::f(int a) { if (!g) m(a); }