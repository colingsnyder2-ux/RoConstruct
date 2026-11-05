// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00756660;
int func_00756660() { int x=g_00756660; x &= ~1; g_00756660=x; return x; }
