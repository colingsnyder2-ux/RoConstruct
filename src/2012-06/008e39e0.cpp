// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x3b8]; int v; void g(); int f(); }; int S::f(){ g(); return v; }