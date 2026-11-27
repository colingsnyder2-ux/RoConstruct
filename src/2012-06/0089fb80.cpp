// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct D { int a[7]; };
struct Mouse { char pad[0x80]; D d; void set(const D* v); };
void Mouse::set(const D* v){ d = *v; d.a[0] = 0; }
