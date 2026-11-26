// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub { char d[16]; Sub(); };
struct E { Sub s; int f14; E(); virtual void v(); };
E::E() : f14(0) {}
void E::v() {}