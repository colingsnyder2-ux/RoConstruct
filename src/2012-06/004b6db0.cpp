// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct M { int m(int); };
struct S { char p[0x34]; M x; int f(int a); };
int S::f(int a) { int r = x.m(a); return r < 0 ? r : 0; }