// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
bool h(int);
struct C { void other(int); void f(int a); };
void C::f(int a) { if (!h(a)) other(a); }
