// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Q { void h(void*); };
struct S { S* f(int fl); };
S* S::f(int fl) { if (fl & 1) { int* b = (int*)this - 1; ((Q*)*b)->h(b); } return this; }