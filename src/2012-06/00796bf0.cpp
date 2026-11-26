// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[564]; char q; void h(int,void*); void f(); }; void S::f(){ h(2,&q); }