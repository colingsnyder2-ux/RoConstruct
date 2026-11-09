// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_007550c0;
int func_007550c0() { int x=g_007550c0; x &= ~1; g_007550c0=x; return x; }
