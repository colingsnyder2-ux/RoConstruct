// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct E { int p[10]; ~E(); };
struct H { int a, b; E e[40]; };
struct N { char pad[0xc]; H* h; void f(); };
void N::f() { delete h; }
