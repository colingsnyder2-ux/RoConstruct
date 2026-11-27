// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ int* p; int v; }; struct S{ char pad[0xec]; int* a; int i; R m(); };
R S::m(){ R r; r.p=&a[i]; r.v=a[i]; return r; }

