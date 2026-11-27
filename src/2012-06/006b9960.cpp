// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct I { virtual void d0(); virtual unsigned v1(); };
struct S { void g(int, unsigned); void f(int a, I* o); };
void S::f(int a, I* o){ g(a, o->v1()); }
