// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct G{ virtual void a(); virtual void b(); virtual bool c(void*); }; G* gp; struct A{ char p[0x1ac]; char* q; bool f(){ if(q) return gp->c(q+0x1c); return false; } }; bool k(A*a){return a->f();}
