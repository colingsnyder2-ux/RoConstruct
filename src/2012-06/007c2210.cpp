// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x2c8]; char q; void g(void*); void f(void*); }; void S::f(void*){ g(&q); }