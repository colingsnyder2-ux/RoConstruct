// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ char p[0x1ac]; int x; };
struct S{ char p[0x1a30]; B* q; int f(); };
int S::f(){ return q ? q->x : 0; }
