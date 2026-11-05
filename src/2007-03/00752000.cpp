// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00752000;
int func_00752000() { int x=g_00752000; x &= ~1; g_00752000=x; return x; }
