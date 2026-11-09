// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00756570;
int func_00756570() { int x=g_00756570; x &= ~1; g_00756570=x; return x; }
