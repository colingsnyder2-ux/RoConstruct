// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00759e40;
int func_00759e40() { int x=g_00759e40; x &= ~1; g_00759e40=x; return x; }
