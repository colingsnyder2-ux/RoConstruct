// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A { char pad[0x210]; int f; };
extern int g_n;
struct S { char pad[0x838]; unsigned char t[1000]; unsigned char get(A* a, A* b); };
unsigned char S::get(A* a, A* b) { return t[(a->f + g_n * 10) * 10 + b->f]; }
