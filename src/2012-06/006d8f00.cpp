// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
struct X { int v; __declspec(dllimport) void m(); };
struct S { bool b; X x; void f(); };
void S::f() { if (b) { x.m(); b = false; } }