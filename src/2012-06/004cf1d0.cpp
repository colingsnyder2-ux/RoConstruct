// from server: 83% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C1 { virtual void a(); };
struct C2 { virtual void b(); };
struct C3 { virtual void c(); };
struct P { int x; };
struct D : P, C3, C2, C1 { ~D(); };
D::~D() {}