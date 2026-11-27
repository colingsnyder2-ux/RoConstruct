// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ char pad[0x94]; int v; }; struct Q{ R* g(); }; struct S{ char pad[0x10]; Q q; bool m(); };
bool S::m(){ return q.g()->v==1; }
