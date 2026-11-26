// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct T; void g(T*,void*); struct A{ int p; T* f(T* r){ g(r,(char*)this+4); return r; } }; T* k(A*a,T*r){return a->f(r);}
