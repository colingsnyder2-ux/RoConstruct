// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S{ char pad[0x45]; bool b; void m(bool x); }; void S::m(bool x){ b=x; }

