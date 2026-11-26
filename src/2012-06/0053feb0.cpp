// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x1bc]; int x; bool f(); };
bool S::f(){ return x == 1 || x == 2; }
