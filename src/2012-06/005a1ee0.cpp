// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void g(int, const char*, int); };
extern char sym[];
struct S{ char p[0x20]; B* b; int x; bool f(int); };
bool S::f(int a){ b->g(x, sym, a); return true; }
