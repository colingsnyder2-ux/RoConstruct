// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ char p[0xd5]; bool fl; }; struct A{ char p[0xc]; B* b; void h(); void f(); };
void A::f(){ b->fl=true; h(); }
