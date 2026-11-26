// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x9c]; int x; void g(int); void f(int); }; void S::f(int a){ if(x) g(a); }