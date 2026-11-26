// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ virtual void v0(int); virtual void v1(int); virtual void v2(int); virtual void v3(int); virtual void v4(int); virtual void v5(int); virtual void v6(int); virtual void v7(int); virtual void v8(int); virtual void v9(int); virtual void v10(int); virtual void v11(int); };
struct S{ char p[0xe0]; B* b; void f(); };
void S::f(){ B* p = b; if(p) p->v11(1); }
