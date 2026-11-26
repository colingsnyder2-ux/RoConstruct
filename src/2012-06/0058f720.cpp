// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ char p[0x1f54]; bool fl; void h(int,int); void f(int,int); };
void A::f(int a,int b){ if(fl) h(a,b); }
