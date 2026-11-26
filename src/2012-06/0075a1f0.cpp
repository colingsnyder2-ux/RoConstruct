// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P { char p[0x1c]; };
struct B { int x; };
struct D : P, B {};
struct S { int a, b; int off; double f(B* b); };
double S::f(B* b) { D* d = static_cast<D*>(b); return *(double*)((char*)d + off); }