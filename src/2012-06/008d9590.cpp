// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct T { int x; void g(int a, float b, float c); };
struct S { char pad[0x10]; T t; void f(int a, float b, float c); };
void S::f(int a, float b, float c) { t.g(a, b, c); }
