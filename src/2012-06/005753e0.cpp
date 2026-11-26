// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S{int a,b;};
struct D{ void* A(S*); };
void B(void*, void*);
void f(D* d, void* e){ S s; B(e, d->A(&s)); }
