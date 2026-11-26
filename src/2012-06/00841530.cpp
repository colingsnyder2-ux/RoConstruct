// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern char sym[];
void g(int, const char*);
int f(int a, int b){ g(b, sym); return 1; }
