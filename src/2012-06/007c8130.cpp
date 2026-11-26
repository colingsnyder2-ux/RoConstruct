// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct A{virtual void v0();virtual void v1();virtual int v2(int);}; struct B{void h(int);}; struct S{char pad[0x2c];A*a;B*b;void f(int x);}; void S::f(int x){ b->h(a->v2(x)); }
