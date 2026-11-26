// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ virtual void v0(); virtual void v1(); virtual void v2(); };
struct S{ char p[0x88]; B* b; void f(); };
void S::f(){ if(b) b->v2(); }
