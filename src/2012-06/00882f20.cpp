// from server: 93% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A1{int a;}; struct B1{int b;}; struct C: A1,B1{ void m(int,double); };
struct S{ void (C::*pmf)(int,double); C* obj; int pad; int i; int pad2; double d; };
void f(S** pp){ S* s=*pp; (s->obj->*s->pmf)(s->i, s->d); }
