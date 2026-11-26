// from server: 77% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P { char pad[0x104]; void* m; };
void G(void*);
struct S { int a; P* p; void f(); };
void S::f() { G(p->m); }