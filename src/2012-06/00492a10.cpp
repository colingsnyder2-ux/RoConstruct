// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD

struct I { virtual void d0(){} virtual void d1(){} virtual void d2(){} virtual void d3(){} virtual void d4(){} virtual int v5(); };
struct P { char pad[0xc8]; I i; };
struct T { char pad[0xc]; P* p; bool f(); };
bool T::f(){ return p->i.v5() > 0; }
