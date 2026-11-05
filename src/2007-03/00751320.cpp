// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00751320;
int func_00751320() { int x=g_00751320; x &= ~1; g_00751320=x; return x; }
