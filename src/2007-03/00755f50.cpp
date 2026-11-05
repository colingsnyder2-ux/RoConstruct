// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00755f50;
int func_00755f50() { int x=g_00755f50; x &= ~1; g_00755f50=x; return x; }
