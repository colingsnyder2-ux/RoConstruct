// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00753c60;
int func_00753c60() { int x=g_00753c60; x &= ~1; g_00753c60=x; return x; }
