// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern int g;
struct S { void h(); void f(int a, int b); };
void S::f(int a, int b) { if (a == g) h(); }