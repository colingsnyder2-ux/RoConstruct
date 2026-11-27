// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ void g(int); }; struct S{ char p[0x80]; bool fl; char q[3]; R r; void f(int a); }; void S::f(int a){ a=fl; r.g(a); }
