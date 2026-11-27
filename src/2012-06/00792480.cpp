// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct I{ virtual void v0(int,int,int)=0; };
void f(I* p,int a,int b,int c){ p->v0(a,b,c); }
