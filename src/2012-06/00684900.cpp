// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern char g[];
struct S { char pad[0x60]; char m; void f(char v); void h(const char*); };
void S::f(char v) { if (m != v) { m = v; h(g); } }