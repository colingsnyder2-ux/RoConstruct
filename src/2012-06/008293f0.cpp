// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct X { char pad[0x10c]; char* y; };
struct C { char pad[0x28]; X* x; char* f(); };
char* C::f(){ char* p = x->y; return p ? p - 0x90 : 0; }
