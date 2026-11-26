// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g;
struct S { void f(char c); };
void S::f(char c) { if (c != g) g = c; }