// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GF /GS- /EHsc /MD /Ob1 /Oy-

struct T { void m(); };
struct H { char pad[0x150]; int a; T* b; void f(int); };
void H::f(int){ if (a && b) b->m(); }
