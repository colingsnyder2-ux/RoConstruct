// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SP { void* p; void m(); typedef void (SP::*bt)(); operator bt() const { return p ? &SP::m : 0; } void reset(int); };
extern SP g;
void __stdcall f(int a) { if (g) g.reset(a); }
