// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Block { char pad[0x114]; bool b; int g(int, bool); int f(int a); };
int Block::f(int a){ return g(a, b); }
