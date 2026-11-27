// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct I { virtual void v(int); };
struct S { bool b; I i; void f(); };
void S::f(){ if (b) { i.v(0); b = false; } }
