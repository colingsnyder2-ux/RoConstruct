// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O1 /GS- /EHsc /MD
struct C{ char p[0x104]; char v; }; struct B{ char p[0x20]; C* c; }; struct A{ int x; B* b; }; A* __cdecl g(); char f(){ return g()->b->c->v; }