// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { unsigned char Get(int); void Set(int, unsigned char); void f(int a); };
void S::f(int a){ Set(a, Get(a)); }
