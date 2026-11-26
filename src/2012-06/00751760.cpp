// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ char p[0x3c]; int x; }; struct P{ R* g(); }; struct A{ char p[0x198]; P* q; int* f(); };
int* A::f(){ return &q->g()->x; }
