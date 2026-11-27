// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Sub { char pad[8]; int x; void m(int v, std::string s); };
struct S { char pad[0x10]; void f(std::string s); };
void S::f(std::string s) { Sub* p = (Sub*)((char*)this + 0x10); p->m(p->x, s); }
