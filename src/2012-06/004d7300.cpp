// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct V{int a,b,c;}; struct M{int g(V*,int);}; struct S{char pad[0x4594]; M m; int f(int);}; int S::f(int a){ V t; return m.g(&t,a); }
