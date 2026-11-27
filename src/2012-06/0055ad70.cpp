// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ char pad[0x1a04]; char b; }; R* h(); char f(){ R* r=h(); if(r) return r->b; return 0; }

