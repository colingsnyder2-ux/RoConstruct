// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C{ __declspec(dllimport) void m(int); }; extern C g; void f(int a){ g.m(a); }