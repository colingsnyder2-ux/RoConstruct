// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00751180;
int func_00751180() { int x=g_00751180; x &= ~1; g_00751180=x; return x; }
