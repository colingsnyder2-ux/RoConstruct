// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00758ab0;
int func_00758ab0() { int x=g_00758ab0; x &= ~1; g_00758ab0=x; return x; }
