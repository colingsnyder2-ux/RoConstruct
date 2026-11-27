// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct E{ int a[12]; }; E tbl[10]; struct S{ char pad[0x90]; int i; int m(); }; int S::m(){ return tbl[i].a[0]; }
