// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x74]; int m; void a(); void b(); void c(); void f(); };
void S::f(){ if(m==2) a(); else if(m==1) b(); else c(); }
