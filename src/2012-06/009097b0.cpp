// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct N{ int p; N* next; N* f(); }; N* N::f(){ return next ? next->f() : this; }