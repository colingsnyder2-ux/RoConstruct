// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct M { void m(void*); };
struct S { char p[0x1a4]; M sub; void* f(void* a); };
void* S::f(void* a) { volatile int z = 0; sub.m(a); return a; }