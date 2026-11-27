// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct P;
void __cdecl g(P*, P*);
struct P { P* f(P* a, int b); };
P* P::f(P* a, int b){ volatile int z = 0; g(a, this); return a; }
