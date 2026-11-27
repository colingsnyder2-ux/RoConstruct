// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x90]; void* v; void calc(); void* f(); }; void* S::f(){ if(!v) calc(); return v; }
