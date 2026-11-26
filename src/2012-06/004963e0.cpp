// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct P{void g(int);}; struct S{char pad[0xd0]; P* p; void h(); void f(int);}; void S::f(int){ if(p) p->g(0); h(); }
