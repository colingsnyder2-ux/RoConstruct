// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ int g(int); }; struct S{ char p[0x2c]; T* t; int f(int); }; int S::f(int a){ if(!t) return 0; return t->g(a); }