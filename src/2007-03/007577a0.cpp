// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_007577a0;
int func_007577a0() { int x=g_007577a0; x &= ~1; g_007577a0=x; return x; }
