// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
void __stdcall G(int, int);
struct S { int m; void f(int a); };
void S::f(int a) { G(m, a); }