// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
struct V { int a, b, c; };
void f(V* p) { p->a = 0; p->b = 0; p->c = 0; }