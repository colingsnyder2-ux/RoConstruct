// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void g(void*); struct S{char pad[0x2c]; void* p; void h(); void f();}; void S::f(){ g(p); h(); }
