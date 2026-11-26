// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x20]; int a; int b; int f(int); };
int S::f(int x){ if(x == 0) return a; return b; }
