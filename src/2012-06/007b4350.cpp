// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x2c8]; int m; void f(int* o); }; void S::f(int* o){ if(m!=1) *o=0; }
