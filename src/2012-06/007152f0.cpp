// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct O { char p[0x10]; bool b; };
extern O* go;
bool h(int);
void f(int a) { go->b = h(a); }