// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x3c]; char q; void h(void*); void f(); }; void S::f(){ h(&q); }