// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ virtual void a(); virtual void b(); virtual void c(); virtual void d(int); int g(); void f(); }; void S::f(){ int r=g(); d(r); }
