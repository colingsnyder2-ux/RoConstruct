// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{char d[68];}; void* thr(); void* alloc(unsigned n, void* z); struct V{ int pad; T* b; T* e; T* c; bool f(unsigned n); }; bool V::f(unsigned n){ b=0;e=0;c=0; if(n==0) return false; void* z=0; if(n>0x3c3c3c3) z=thr(); b=(T*)alloc(n,z); e=b; c=b+n; return true; }
