// from server: 79% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ char pad[0x110]; char f; }; struct D{ char pad[0x20]; B* b; }; struct E{ int a; D* d; };
E* get(); struct S{ bool m(); };
bool S::m(){ return !get()->d->b->f; }

