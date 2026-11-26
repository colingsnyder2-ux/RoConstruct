// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
struct S{ char p[0x45]; char c; char f(); }; char S::f(){ return c; }