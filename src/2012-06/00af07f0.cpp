// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
__declspec(dllimport) int __stdcall imp1(); int g1; void f(){ g1 = imp1(); }