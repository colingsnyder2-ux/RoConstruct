// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GF /GS- /EHsc /MD /Ob1
struct VB{virtual void f(int*);}; struct B1{virtual void z(); char p[0x1c];}; struct B2{int* m(int* a);}; struct D: B2, virtual VB{ char p[0x20]; }; int* B2::m(int* a){ D& d=*(D*)((char*)this-0x24); d.f(a); return a; }
