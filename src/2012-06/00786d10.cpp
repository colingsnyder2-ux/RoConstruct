// from server: 57% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct P0 { virtual void a(); };
struct P1 { virtual void b(); int d[4]; };
struct P2 { virtual void c(); };
struct P3 { virtual void e(); };
struct Base : P0, P1, P2, P3 { virtual ~Base(); char pad[0x84 - 0x20]; };
struct Member { ~Member(); };struct Mid : Base { virtual ~Mid() {} }; struct Derived : Mid { Member m; virtual ~Derived(); }; Derived::~Derived() {}
