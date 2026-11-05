// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00752120;
int func_00752120() { int x=g_00752120; x &= ~1; g_00752120=x; return x; }
