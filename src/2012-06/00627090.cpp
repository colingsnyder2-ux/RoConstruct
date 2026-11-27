// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S { __declspec(dllimport) int m(int,int,int); };
__declspec(dllimport) void __stdcall fn(int);
void f(S* a, int b, int c, int d) { fn(a->m(b, c, d)); }
