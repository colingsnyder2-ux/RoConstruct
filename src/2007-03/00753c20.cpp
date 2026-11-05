// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00753c20;
int func_00753c20() { int x=g_00753c20; x &= ~1; g_00753c20=x; return x; }
