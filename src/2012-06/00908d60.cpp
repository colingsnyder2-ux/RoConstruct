// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern int g;
struct S{ char p[0xa8]; int v; void f(); };
void S::f(){ v = ++g; }
