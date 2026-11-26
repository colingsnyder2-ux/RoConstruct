// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /fp:fast /GS- /EHsc /MD
struct S{ char p[0x14]; int n; float f(); }; float S::f(){ return 100.0f/n; }
