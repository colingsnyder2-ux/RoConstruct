// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S; struct I{ virtual void v0(); virtual void v1(S*,int); }; struct S{ void f(I* p,int b); }; void S::f(I* p,int b){ p->v1(this,b); }
