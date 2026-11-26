// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct A{char p[0x20]; int a; int pad; int b; void f(int x){ if(!x){ a=x; return;} a=1; b=x; } }; void g(A*p,int x){p->f(x);}
