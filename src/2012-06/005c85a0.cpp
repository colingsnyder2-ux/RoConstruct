// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int f(unsigned a, unsigned b) { if (b != a) { unsigned d = (b - a) & 0xffffff; if (d < 0x7fffff) return 1; } return 0; }
