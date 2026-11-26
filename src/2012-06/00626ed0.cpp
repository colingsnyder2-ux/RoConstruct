// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
__declspec(dllimport) int __stdcall imp(int, int);
int f(int a, int b) { return imp(a, b); }