// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T { char pad[0x68]; void* m; };
struct P { T* g(); };

void* f(P* p){ if (p) { T* t = p->g(); if (t) { if (t->m) return t->m; } } return 0; }
