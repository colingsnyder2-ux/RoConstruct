// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S{char pad[0xb8]; bool x; char q; bool y; int g(int,int); int f(int,int);}; int S::f(int a,int b){ if(x && !y) return 0; return g(a,b); }
