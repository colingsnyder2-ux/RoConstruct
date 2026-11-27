// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
struct E { int a[10]; };
struct D { char pad[0x20]; std::vector<E> v; };
struct B { char pad[0x14]; D* d; int f(); };

int B::f(){ return (int)d->v.size(); }
