// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct W { char p[0x134]; struct X { bool m(); } x; };
W* __cdecl g(void*);
struct S { char p[12]; void* f0; bool f(); };
bool S::f() { W* w = g(f0); if (w) return w->x.m(); return false; }