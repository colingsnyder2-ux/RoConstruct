// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern int gflag; struct M{void g();}; struct S{char pad[0x104]; M m; void h(); void f();}; void S::f(){ if(gflag) m.g(); h(); }
