// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00757040;
int func_00757040() { int x=g_00757040; x &= ~1; g_00757040=x; return x; }
