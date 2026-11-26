// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Q{int a; void (*fn)(void*);}; struct T{int a; Q* q; int r;}; void __stdcall f(T* p){ if(p->q) p->q->fn(&p->r); }
