// from server: 61% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct M { virtual void d0(){} virtual void d1(){} virtual void d2(){} virtual void d3(){} virtual void d4(){} virtual void d5(){} virtual void d6(){} virtual void d7(){} virtual void d8(){} virtual void d9(){} virtual void d10(){} virtual void v(int,int,int); char pad[0x18]; unsigned flags; void f(int a,int b,int c); };
void M::f(int a,int b,int c){ if ((flags>>2)&1) v(a,b,c); }
