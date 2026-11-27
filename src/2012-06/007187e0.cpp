// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int g(int, int, int, int, int, int, int);
int f(int a, int b, int c, int d, int e) { return g(a, b, c, 0, 0, d, e); }
