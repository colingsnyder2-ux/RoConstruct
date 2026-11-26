// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct T; void g(T*,int); T* f(T* p,int q){ g(p,q); return p; }
