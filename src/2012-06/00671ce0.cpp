// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S{ float g(); double m(); }; double S::m(){ return g()*1.1; }
