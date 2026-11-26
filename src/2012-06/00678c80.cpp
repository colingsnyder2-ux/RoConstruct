// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char p[0x168]; double d;}; S* g();
double f(){ return g()->d; }
