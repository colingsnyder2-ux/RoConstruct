// from server: 80% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int x; };
struct P { int a,b; };
int __stdcall g(R*,P);
struct A { int vp; P p; int f(); };
int A::f(){ R r; return g(&r, p); }
