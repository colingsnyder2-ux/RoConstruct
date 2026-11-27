// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Q{ void g(); }; struct S{ char pad[0x218]; Q* q; int m(int); };
int S::m(int){ q->g(); return 1; }
