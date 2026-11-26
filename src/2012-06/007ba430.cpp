// from server: 90% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
int __stdcall g(unsigned,int); struct S{char pad[0x115]; unsigned char c; int f(int);}; int S::f(int a){ return g(c,a); }
