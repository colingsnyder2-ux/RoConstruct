// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct V { int a, b, c, d; };
void __stdcall f(V* p, int x, int y) { volatile int z = 0; p->b = 0; p->c = 0; p->d = 0; }