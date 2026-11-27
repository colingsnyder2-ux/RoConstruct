// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B { void notify(void*); };
static int g1, g2;
struct D : B { char pad[868 - 1]; int v; void set(int); };
void D::set(int a) { if (v != a) { v = a; notify(&g1); notify(&g2); } }