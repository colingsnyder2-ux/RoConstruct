// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void g1(void* L, const char* s);
void g2(void* L, int n, const char* s);
void f(void* L, int n) { g1(L, "The metatable is locked"); g2(L, n - 1, "__metatable"); }
