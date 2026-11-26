// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B1{ char p[0x18]; virtual ~B1(); };
struct B2{ virtual void v(); };
struct D : B1, B2 { virtual ~D(); };
D::~D(){ }
