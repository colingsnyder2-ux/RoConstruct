// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct M{ void g(); }; struct A{ char p[0x20]; M m; void f(); }; void A::f(){ int a[3]; m.g(); }
