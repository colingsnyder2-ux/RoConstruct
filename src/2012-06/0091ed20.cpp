// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R{ char p[0x1b0]; char x; };
R* g(int);
bool f(int a){ return g(a)->x == 0; }
