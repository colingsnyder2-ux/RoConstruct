// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern volatile int g_00752f80;
int func_00752f80() { int x=g_00752f80; x &= ~1; g_00752f80=x; return x; }
