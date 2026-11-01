// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct L { virtual void a(); virtual void b(); };
struct S { char pad[0x100]; int enabled; L* l; void f(int); };
void S::f(int) { if (enabled) { L* p = l; if (p) p->b(); } }
