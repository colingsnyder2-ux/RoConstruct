// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{char pad[0x18]; unsigned lim; unsigned c; void g();}; struct S{char pad[0x1c]; T* t; void f(int);}; void S::f(int){ T* p=t; if(++p->c >= p->lim){ p->c=0; p->g(); } }
