// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

struct R { int a,b,c; }; struct A { int x; };
struct M { void g(R*, A*); };
struct S { char p[0x94]; M m; void f(A a); };
void S::f(A a){ R r; m.g(&r,&a); }
