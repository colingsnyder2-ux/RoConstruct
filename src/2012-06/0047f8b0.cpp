// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S2{ void g(void*, void**); }; void* f(void* a, S2* b, void* c){ volatile int z=0; b->g(a,&c); return a; }
