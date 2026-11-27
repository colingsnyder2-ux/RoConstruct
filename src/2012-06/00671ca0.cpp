// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S{ char pad[0xa4]; float v; float m(); }; float S::m(){ return v; }
