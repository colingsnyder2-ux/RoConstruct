// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct D { char pad[0x104]; bool flag; void g(bool); void f(); };
void D::f(){ g(!flag); }
