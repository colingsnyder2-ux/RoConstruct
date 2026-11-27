// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD

struct D { void m(int); };
struct P { int a,b,c; D *d; };
long __stdcall f(P *p){ if (!p->d) return 0x80004005; p->d->m(1); return 0; }
