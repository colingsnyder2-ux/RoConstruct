// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_0075bc00;
int func_0075bc00() { int x=g_0075bc00; x &= ~1; g_0075bc00=x; return x; }
