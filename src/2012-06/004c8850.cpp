// from server: 90% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct M{M();}; struct S{int pp; short a; short b; char c; char p[3]; M m; S(); }; S::S():m(),a(0),b(0),c(0){}
