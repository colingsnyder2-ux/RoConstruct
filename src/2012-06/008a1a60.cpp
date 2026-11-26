// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A; void __stdcall g(A*,int); struct S{char pad[0x48]; unsigned char fl; void h(A*); void f(A*); }; void S::f(A* a){ g(a,fl); h(a); }
