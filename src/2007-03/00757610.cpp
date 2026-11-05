// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00757610;
int func_00757610() { int x=g_00757610; x &= ~1; g_00757610=x; return x; }
