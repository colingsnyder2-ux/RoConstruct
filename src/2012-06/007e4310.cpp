// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X { void h(); }; struct Y { void k(); };
struct A { char pad[0x40]; Y* y; X* g(int); void f(); };
void A::f(){ g(0)->h(); if (y) y->k(); }
