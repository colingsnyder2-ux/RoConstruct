// from server: 79% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct N { N* n; N* p; };
struct S { int a; N h; int c; S(); };
S::S() { a = 0; N* hh = &h; char z = 0; *(volatile char*)&z = 0; hh->n = hh; hh->p = hh; c = 0; }
