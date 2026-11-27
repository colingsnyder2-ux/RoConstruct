// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void* g1(void*);
void g2(void*, void*);
void f(char* a, void* b) { a = *(char**)g1(a + 4); g2(b, &a); }