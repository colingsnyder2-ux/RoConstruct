// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void (*M)(void*, void*, int);
M* g;
char buf[8];
void f(){ if (g) { M m = *g; if (m) m(buf, buf, 2); g = 0; } }
