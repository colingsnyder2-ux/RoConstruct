// from server: 89% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B0 { virtual void f0(); int p; };
struct B1 { virtual ~B1(); int a, b, c; B1(int x) : a(0), b(x) {} };
struct M { M(int); int d[4]; };
struct D : B0, B1 { M m; D(int a0, int a1); virtual void f0(); virtual ~D(); };
D::D(int a0, int a1) : B1(a1), m(a0) {}