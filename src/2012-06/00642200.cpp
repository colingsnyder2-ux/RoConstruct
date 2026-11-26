// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
struct T{char p[0x28]; int v;}; int f(T* t){ if(!t) return -1; return t->v; }
