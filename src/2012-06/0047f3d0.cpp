// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Q { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void release(); };
struct Base { char pad[0x50]; virtual ~Base(); };
struct Hold { Q* q; ~Hold() { if (q) q->release(); } };
struct P2 { virtual ~P2() {} Hold h; };
struct D : Base, P2 { virtual ~D(); };
D::~D() throw() {}
