// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
void G(int*, int, int);
int* f(int* a, int b, int c) { G(a, b, c); return a; }