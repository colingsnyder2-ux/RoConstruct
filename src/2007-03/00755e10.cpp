// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00755e10;
int func_00755e10() { int x=g_00755e10; x &= ~1; g_00755e10=x; return x; }
