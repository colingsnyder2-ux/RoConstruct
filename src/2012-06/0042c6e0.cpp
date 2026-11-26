// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ void m(int); }; struct A{ int a,b,c; void (T::*fn)(int); T* o; void f(int); };
void A::f(int x){ (o->*fn)(x); }
