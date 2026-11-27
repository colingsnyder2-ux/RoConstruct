// from server: 90% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct L { char b[16]; __declspec(dllimport) L* init(); __declspec(dllimport) ~L(); };
struct P { __declspec(dllimport) void m(L*); };
struct S { char pad[0xb4]; P* p; void f(); };
void S::f() { L l; p->m(l.init()); }