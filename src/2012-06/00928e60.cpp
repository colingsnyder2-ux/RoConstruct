// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ char p[0xa0]; int x; A* f(); };
A* A::f(){ x=0; return this; }
