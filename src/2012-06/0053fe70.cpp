// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I { char p[0x38]; I* par; bool f(const I* x); };
bool I::f(const I* x) { while (x) { x = x->par; if (x == this) return true; } return false; }