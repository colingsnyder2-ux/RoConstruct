// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0xc0]; int* a; int n; int f(); };
int S::f(){ if(n > 0) return *a; return 0; }
