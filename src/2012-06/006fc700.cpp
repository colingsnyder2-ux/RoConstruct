// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void g(); }; struct A{ char p[0xac]; B b; void f(int); };
void A::f(int){ b.g(); }
