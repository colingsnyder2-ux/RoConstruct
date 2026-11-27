// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct I { virtual void v(int); };
struct V { char pad[0xfc]; int m; void f(I* o); };
void V::f(I* o){ o->v(m != 0); }
