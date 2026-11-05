// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00759f00;
int func_00759f00() { int x=g_00759f00; x &= ~1; g_00759f00=x; return x; }
