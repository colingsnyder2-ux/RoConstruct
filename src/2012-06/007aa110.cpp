// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x80]; bool ok; float v; void calc(); float f(); }; float S::f(){ if(!ok) calc(); return v; }
