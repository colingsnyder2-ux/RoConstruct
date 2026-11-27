// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X { int a; };
X gObj;
struct T { void g(X*); void f(X* p); };
void T::f(X* p){ if (p == &gObj) g(0); }
