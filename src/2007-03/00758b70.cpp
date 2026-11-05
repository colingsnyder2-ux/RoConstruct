// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00758b70;
int func_00758b70() { int x=g_00758b70; x &= ~1; g_00758b70=x; return x; }
