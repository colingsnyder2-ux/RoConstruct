// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{int v;}; __declspec(dllimport) void __cdecl g(S);
void f(S s){ g(s); }
