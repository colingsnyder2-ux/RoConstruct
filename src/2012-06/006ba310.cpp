// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
__declspec(dllimport) int __stdcall imp(int, int);
void __stdcall g(int);
void f(char c, int a, int b) { if (!c) g(imp(a, b)); }