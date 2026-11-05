// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Inner { void add(void* x); };
struct Obj { int a, b; Inner inner; void* put(void* x); };
void* Obj::put(void* x) { inner.add(x); return x; }
