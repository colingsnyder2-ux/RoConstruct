// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x38]; S* n; bool f(S* p);}; bool S::f(S* p){ while(p){ if(p==this) return true; p=p->n; } return false; }
