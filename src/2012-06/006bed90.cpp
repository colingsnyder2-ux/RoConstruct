// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct I { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual int v(int,int); };
struct S { char pad[0x10]; I* i; int pad2; int a; int f(int b); };
int S::f(int b){ return i->v(a,b); }
