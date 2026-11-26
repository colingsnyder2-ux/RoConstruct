// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ void g(); void f(void*,int); }; void S::f(void* a,int){ if(a) g(); }