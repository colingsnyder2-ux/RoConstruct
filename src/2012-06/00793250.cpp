// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct I{ virtual void v0(int,int)=0; };
struct S{ char p[0x84]; I* q; void f(int a,int b); }; void S::f(int a,int b){ if(q) q->v0(a,b); }
