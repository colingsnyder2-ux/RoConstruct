// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E{ char pad[0xc]; int* p; }; bool f(E* a,E* b){ return *a->p < *b->p; }
