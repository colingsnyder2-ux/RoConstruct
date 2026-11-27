// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ virtual void v0(){} virtual void v1(){} virtual void v2(){} virtual void v3(){} virtual void f(void*,int); };
struct S{ int pad[2]; char b[8]; void m(A* a,int x); };
void S::m(A* a,int x){ a->f(b,x); }
