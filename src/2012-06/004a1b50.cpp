// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void u(); void v(); }; struct A{ char p[0x54]; B* b; void w(); void f(); };
void A::f(){ w(); b->u(); }
