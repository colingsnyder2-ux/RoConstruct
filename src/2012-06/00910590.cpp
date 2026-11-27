// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{void g();}; T* __stdcall f(T* b,int){ b->g(); return b; }
