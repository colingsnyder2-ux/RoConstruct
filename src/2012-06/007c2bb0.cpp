// from server: 92% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern bool g;
struct VB { bool m(); };
struct A { char pad[0x84]; };
struct D : A, virtual VB { bool f(); };
bool D::f() { if (g) return true; return m(); }