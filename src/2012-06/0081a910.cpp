// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct O { void m(int, int); };
struct S { char pad[0x80]; O* o; void f(int a); };
void S::f(int a) { o->m(a, 0); }