// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct U { void rel(); };
struct T { char d[0x18]; U u; };
void __cdecl del(void*);
struct S { T* p; void f(); };
void S::f() { T* q = p; if (q) { q->u.rel(); del(q); } }