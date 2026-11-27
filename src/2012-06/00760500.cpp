// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X{char a[0x1c];}; struct B{int b;}; struct D: X, B{};
struct S{ int pad[2]; float D::*mp; float f(B* p); }; float S::f(B* p){ return static_cast<D*>(p)->*mp; }
