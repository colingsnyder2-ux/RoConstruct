// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S { char p[0x250]; double a, b, c; double f(); };
double S::f() { return c + b + a; }