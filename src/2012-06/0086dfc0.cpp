// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct O { int* conv(); };
struct C { char pad[0x84]; int* p; void f(int a, O* b); };
void C::f(int a, O* b) { p = 0; if (b) p = b->conv(); }
