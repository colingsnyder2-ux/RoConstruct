// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct V { void* h(void**); };
struct O { };
typedef void (__thiscall *F)(O*, int, void*);
struct C { char pad[0x28]; O* o; void f(int a, V* b); };
void C::f(int a, V* b) { O* p = o; F* slot = (F*)(*(char**)p + 0xc); void* r = b->h((void**)&b); (*slot)(p, a, r); }
