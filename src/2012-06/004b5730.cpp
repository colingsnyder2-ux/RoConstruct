// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int a, b, c, d; void f(const S* o); };
void S::f(const S* o) { *this = *o; }