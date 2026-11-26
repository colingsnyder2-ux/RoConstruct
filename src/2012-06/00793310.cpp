// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ virtual void v0(int); virtual void v1(int); virtual void v2(int); virtual void v3(int); };
struct S{ char p[0x88]; B* b; void f(int); };
void S::f(int a){ if(b) b->v3(a); }
