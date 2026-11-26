// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X{ __declspec(dllimport) int m(int); }; struct A{ X* x; int y; int f(); };
int A::f(){ return x->m(y); }
