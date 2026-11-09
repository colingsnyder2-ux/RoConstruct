// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00755e90;
int func_00755e90() { int x=g_00755e90; x &= ~1; g_00755e90=x; return x; }
