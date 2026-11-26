// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct A{char pad[0x1c];}; struct Bs{int q;}; struct D:A,Bs{int z;}; struct S{char pad[8]; int D::*pm; int f(Bs* b);}; int S::f(Bs* b){ return static_cast<D*>(b)->*pm; }
