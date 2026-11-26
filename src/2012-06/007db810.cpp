// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct O { void m(int); };
struct S { char pad[0x80]; int v; O o; void f(int); };
void S::f(int) { o.m(v); }