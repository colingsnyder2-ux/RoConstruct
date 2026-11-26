// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Y { char p[0x2c]; int v; };
struct X { char p[0x45e0]; Y m; };
struct S { char p[0x170]; X* a; char q[0x210 - 0x174]; int n; bool f(); };
bool S::f() { Y* y = &a->m; if (y && n <= y->v) return true; return false; }