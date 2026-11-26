// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ char p[0x1cc]; int* b; int* e; int f(); };
int A::f(){ return e-b; }
