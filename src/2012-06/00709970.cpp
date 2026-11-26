// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
struct B{char p[0x18]; int m;}; void g(void*,int,int); void f(void* a,B* b){ g(a,-10000,b->m); }
