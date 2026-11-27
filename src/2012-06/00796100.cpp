// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct VB { void m(); };
struct B0 { char pad[0x138]; };
struct D : B0, virtual VB { };
struct Slot { char pad[0x10]; void (D::*pmf)(); int pad2; D* obj; void call(); };
void Slot::call() { (obj->*pmf)(); }
