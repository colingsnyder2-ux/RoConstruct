// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{char p[0x98]; float v;}; struct B{char p[0x108]; A* a;}; struct S{char p[0x198]; B* b; float f();}; float S::f(){ return b->a->v; }
