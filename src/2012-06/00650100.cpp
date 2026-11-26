// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void G(char*, int, int, char*);
void f(char* a, int b, int c) { G(a, b, c, a + 8); }