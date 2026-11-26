// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x88]; int** v; int f(); }; int S::f(){ return v ? *v[-8] : 0; }