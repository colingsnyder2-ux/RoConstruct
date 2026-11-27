// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __cdecl imp(int, int, int, int, int);
int f(int a, int b, int c, int d) { return imp(a, b, 0x104, c, d); }
