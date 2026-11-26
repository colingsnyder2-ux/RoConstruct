// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void G(void*, int);
struct S { void* p; int f(int a); };
int S::f(int a) { G(p, a); return 1; }