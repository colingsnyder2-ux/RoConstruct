// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X{ void m(bool); }; struct Y{ char pad[0x198]; X* x; }; struct Z{ Y* a1(); Y* a2(); }; struct HS{ Z* z(); void f(bool b); }; void HS::f(bool b){ Y* y=z()->a1(); if(y) y->x->m(!b); y=z()->a2(); if(y) y->x->m(!b); }
