// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E{ char c[20]; };
struct S{ char p[0x1c]; E* b; E* e; int f(); };
int S::f(){ return e - b; }
