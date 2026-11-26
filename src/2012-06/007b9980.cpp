// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E{ char c[40]; };
struct S{ int p; E* b; E* e; int f(); };
int S::f(){ return e - b; }
