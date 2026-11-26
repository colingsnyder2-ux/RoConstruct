// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ char p[0x14]; int x; }; struct A{ char p[0xf8]; B* b; int f(); };
int A::f(){ return b ? b->x : 0; }
