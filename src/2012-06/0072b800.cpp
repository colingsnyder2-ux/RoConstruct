// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct M{int x; void d();}; struct S{char pad[0xf8]; M a; M b; void f();}; void S::f(){ a.d(); b.d(); }
