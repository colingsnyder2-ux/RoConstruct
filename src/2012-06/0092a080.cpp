// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: C:/Users/Ryan/AppData/Local/Programs/Git/Od /Ob0 /GS- /EHsc /MD
struct E{ char p[0x14]; }; struct S{ int a; E* p; E* f(int i); }; E* S::f(int i){ return p+i; }
