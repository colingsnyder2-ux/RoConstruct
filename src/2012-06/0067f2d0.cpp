// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char p[0x20]; int x;}; S* g();
int f(){ return g()->x; }
