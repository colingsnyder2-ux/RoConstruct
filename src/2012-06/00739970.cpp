// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ void* g(void*,int); }; struct B{ char p[0x94]; void* m; void* f(A* a){ if(a) return a->g(m,0); return this; } }; void* k(B*b,A*a){return b->f(a);}
