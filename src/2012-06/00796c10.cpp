// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[580]; char q; void h(int,void*); void f(); }; void S::f(){ h(4,&q); }