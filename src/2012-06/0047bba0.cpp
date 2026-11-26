// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C{ void g(); }; struct B{ char p[0xbc]; C* c; }; struct A{ char p[0xc]; B* b; void f(); }; void A::f(){ b->c->g(); }