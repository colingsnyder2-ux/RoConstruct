// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B1{int a; void m1();}; struct B2{int b;}; struct T:B1,B2{ void m(int); }; struct A{ int p[4]; void (T::*fn)(int); T* o; void f(int); };
void A::f(int x){ (o->*fn)(x); }
