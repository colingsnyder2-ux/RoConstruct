// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P { void m(float); };
struct S { char pad[0xd0]; P* p; float v; void f(); };
void S::f() { if (p) p->m(v); }