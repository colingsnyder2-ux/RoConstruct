// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void g(int,int); };
struct S{ char p[0xe10]; B b; void f(int,int); };
void S::f(int a,int c){ b.g(c,a); }
