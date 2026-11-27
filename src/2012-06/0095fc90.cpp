// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { char pad[0x1e6]; char flag; };
extern Single* __stdcall getS();
struct B0 { virtual ~B0(); };
struct I1 { virtual void x(); };
struct D : B0, I1 { virtual ~D(); };
D::~D() { getS()->flag = 0; }