// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_007511a0;
int func_007511a0() { int x=g_007511a0; x &= ~1; g_007511a0=x; return x; }
