// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct N{ N* l; char p[0x51]; char nil; };
N* f(N* p){ while(!p->l->nil) p = p->l; return p; }
