// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S; struct O { void m(S*, int); };
struct S { char pad[0xbc]; O o; void f(int a); };
void S::f(int a) { o.m(this, a); }