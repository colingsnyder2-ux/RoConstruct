// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct I { virtual void d0(); virtual void d1(); virtual char* get(int); };
struct M { char pad[0x2c]; I* i; char* f(int a); };
char* M::f(int a){ char* r = i->get(a); return r ? r+0x1c : 0; }
