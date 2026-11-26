// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I { virtual void v0(); virtual void v1(int); };
void f(I* p) { p->v1(0); }