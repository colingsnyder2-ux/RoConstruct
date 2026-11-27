// from server: 92% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B0 { char pad[0x84]; };
struct VB { int x; int get(); };
struct D : B0, virtual VB { int f(); };
extern bool g_flag;
extern int g_obj[4];
int D::f(){ if (g_flag) return (int)g_obj; return get(); }
