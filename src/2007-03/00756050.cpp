// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00756050;
int func_00756050() { int x=g_00756050; x &= ~1; g_00756050=x; return x; }
