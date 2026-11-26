// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
struct P{char p[0x1c]; int v;}; struct B{ int y; }; struct E:P,B{}; int f(B* b){ return static_cast<E*>(b)->v; }
