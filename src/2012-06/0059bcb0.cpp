// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
struct S { char p[0xf54]; unsigned n; int f(); };
int S::f() { return 0 < n; }