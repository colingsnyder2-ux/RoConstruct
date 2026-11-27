// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct E { int a[5]; };
struct V { int pad; E* first; E* last; int f(); };
int V::f(){ return (int)(last - first); }
