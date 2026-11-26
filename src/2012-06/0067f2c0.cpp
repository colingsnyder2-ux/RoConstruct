// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X { char p[0x20]; int v; };
X* g();
int f() { return g()->v << 6; }