// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int a,b,c; };
void f(const V* s, V* d){ if (d) *d = *s; }
