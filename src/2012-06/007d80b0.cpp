// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{int v;}; struct U{ void g(A); }; struct S{ char p[0x10]; U u; void f(A); }; void S::f(A a){ u.g(a); }