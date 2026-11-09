// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00755db0;
int func_00755db0() { int x=g_00755db0; x &= ~1; g_00755db0=x; return x; }
