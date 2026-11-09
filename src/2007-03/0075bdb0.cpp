// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_0075bdb0;
int func_0075bdb0() { int x=g_0075bdb0; x &= ~1; g_0075bdb0=x; return x; }
