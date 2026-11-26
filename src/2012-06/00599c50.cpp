// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S { char g(int, int, int); bool f(int a, int b, int c); };
bool S::f(int a, int b, int c) { return g(a, b, c); }
