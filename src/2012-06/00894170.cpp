// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ char p[0x108]; int v; }; struct S{ char p[0xc]; T* a[1]; int f(int); }; int S::f(int i){ return a[i]->v; }