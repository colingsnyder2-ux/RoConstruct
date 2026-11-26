// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct T { void h(void*); };
T& g();
void* f(void* p) { volatile int z = 0; g().h(p); return p; }