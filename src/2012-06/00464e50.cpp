// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern char g;
struct S { char p[0x10c]; char c; void f(char v); };
void S::f(char v) { c = v; g = v; }