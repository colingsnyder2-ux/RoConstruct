// from server: 81% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
struct T{int a; int b;}; void g(int*); void f(T* p){ g(&p->b); }
