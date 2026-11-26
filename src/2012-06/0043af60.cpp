// from server: 91% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
struct A{}; struct B2{}; struct S: A,B2 { void m(int,unsigned char); }; typedef void (S::*PMF)(int,unsigned char); struct Bind{PMF pmf; S* obj; int x; unsigned char c;}; void f(Bind* b){ (b->obj->*(b->pmf))(b->x,b->c); }
