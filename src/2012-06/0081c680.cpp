// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C{ char p[0x78]; int x; }; struct B{ char p[0x24]; C* c; }; struct A{ char p[0xa4]; B* b; int f(); };
int A::f(){ return b->c->x; }
