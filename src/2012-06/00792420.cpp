// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
int f(int x) { if (x % 4 == 0) { int i = (int)((unsigned)(x - 24) >> 2) - 1; if (i < 16) return i; } return -1; }
