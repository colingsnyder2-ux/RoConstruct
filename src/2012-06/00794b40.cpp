// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern int a,b,c,d;
struct S { bool f(const void*); bool g(const void*); char h(const void*); };
bool S::f(const void* p){ if (p==&a) return true; if (p==&b) return true; if (p==&c) return true; if (p==&d) return true; return false; }
