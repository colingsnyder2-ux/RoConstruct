// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C{ int n; };
extern char sym[];
void __stdcall g(const char*);
struct S{ char p[0x2ec]; int x; void f(C); };
void S::f(C a){ x = a.n; g(sym); }
