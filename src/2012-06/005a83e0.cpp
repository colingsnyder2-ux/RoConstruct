// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct U{ void g(int,int); }; struct S{ char p[0xe10]; U u; void f(int,int); }; void S::f(int a,int b){ u.g(b,a); }