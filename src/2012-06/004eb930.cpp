// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
struct M{int a[16];}; struct X{ char p[0x11c]; M m; void f(M* o){ *o=m; } }; void k(X*x,M*o){x->f(o);}
