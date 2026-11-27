// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ void h(); }; struct S{ T* g(); void f(int); }; void S::f(int){ T* t=g(); if(t) t->h(); }
