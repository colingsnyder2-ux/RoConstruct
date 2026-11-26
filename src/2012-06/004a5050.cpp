// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ virtual void x(); B(); char pad[0xf0]; };
struct D : B { virtual void y(); char c; D(); };
D::D(){ c = 0; }
