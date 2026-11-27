// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void x();
struct P { char pad[0x110]; bool a; bool b; };
struct C { char pad[0x20]; P* p; void f(); };
void C::f() { if (p == 0) { x(); return; } if (!p->a && !p->b) x(); }
