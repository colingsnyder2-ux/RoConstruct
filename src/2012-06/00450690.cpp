// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X{ __declspec(dllimport) void m(int); }; extern int gv; struct A{ char p[8]; X x; void f(); };
void A::f(){ x.m(gv); }
