// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ void g(int,float); }; struct S{ char p[0x10]; R r; void f(int a,float b); }; void S::f(int a,float b){ r.g(a,b); }
