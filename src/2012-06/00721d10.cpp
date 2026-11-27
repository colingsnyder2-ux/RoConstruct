// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct M{void g();}; struct S{char pad[0x1d0]; M m; void h(int); void f();}; void S::f(){ m.g(); h(0); }
