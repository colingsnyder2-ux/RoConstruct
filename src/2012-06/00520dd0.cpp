// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ int p[4]; void (__thiscall *fn)(int); int x; int y; void f(); };
void A::f(){ return fn(y+x); }
