// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ void g(float); }; struct S{ char p[0x10]; R r; void f(float a); }; void S::f(float a){ r.g(a); }
