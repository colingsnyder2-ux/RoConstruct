// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct S { void base(int); virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(int); int f(int); };
int S::f(int a){ base(a); return v3(a); }
