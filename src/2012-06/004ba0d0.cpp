// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void g(int,int); };
struct S{ char p[0xc]; B* b; char p2[0x14]; int x; void f(int); };
void S::f(int a){ b->g(x, a); }
