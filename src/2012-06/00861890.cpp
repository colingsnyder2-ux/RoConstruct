// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x5c]; unsigned fl; void f(bool); };
void S::f(bool v){ fl = (fl & ~4u) | (v ? 4 : 0); }
