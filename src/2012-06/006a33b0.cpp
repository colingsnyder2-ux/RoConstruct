// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct M{int a,k;}; struct P{M* m; char p[0x1c];}; struct B{int x;}; struct D:P,B{}; int f(B*b){ return static_cast<D*>(b)->m->k; }
