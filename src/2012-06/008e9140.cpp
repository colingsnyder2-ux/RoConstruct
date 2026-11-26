// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern char g[];
struct S { char pad[0xb0]; char m[4]; void f(int a); void h(void*, int, void*); };
void S::f(int a) { h(m, a, g); }