// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{bool h();}; T* g(int,int); bool f(int x){ T*p=g(x,1); if(p) return p->h(); return true; }
