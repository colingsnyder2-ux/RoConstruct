// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ virtual void v0(int); virtual void v1(int); virtual void v2(int); virtual void v3(int); virtual void v4(int); };
void f(S* p){ if(p) p->v4(1); }
