// from server: 98% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { int d[6]; Obj(const Obj&); ~Obj(); };
struct X { X* f(int a, Obj o, int b); void g(int a, Obj o); };
X* X::f(int a, Obj o, int b) { g(a, o); return this; }