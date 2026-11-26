// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5(int,int); void f(int); };
void A::f(int a){ v5(a,0); }
