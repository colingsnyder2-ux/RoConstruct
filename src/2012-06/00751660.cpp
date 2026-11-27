// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct S2 { int g(); };
struct T { char pad[0x9c]; S2 s; char p2[0x258-0x9c-1]; bool fl; int f(int); };
int T::f(int){ fl = true; return s.g(); }
