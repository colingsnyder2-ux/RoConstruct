// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A { char pad[0x210]; bool f; };
bool __stdcall f(A* a, A* b) { if (a->f) return true; return b->f ? true : false; }