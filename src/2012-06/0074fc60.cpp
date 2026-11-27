// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A { int x; };
struct M { A* go(A*); };
struct X { char pad[0x9c]; M* m; A* f(A* a); };
A* X::f(A* a) { volatile int z = 0; m->go(a); return a; }