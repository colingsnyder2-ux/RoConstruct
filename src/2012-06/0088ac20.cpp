// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ int g(int); };
struct S{ char p[0x98]; B b; int f(int,int,int); };
int S::f(int a,int,int){ b.g(a); return a; }
