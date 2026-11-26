// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V{ int p; int* b; int* e; }; struct S{ char p[0x8c]; V* v; int f(); }; int S::f(){ return v->e - v->b; }