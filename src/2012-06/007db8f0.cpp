// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct M{ void g(double); }; struct A{ char p[0x80]; double d; M m; void f(int){ m.g(d);} }; void h(A*a){a->f(0);}
