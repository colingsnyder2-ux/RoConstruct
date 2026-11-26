// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
__declspec(dllimport) int __stdcall g(char*);
int __stdcall f(char* p){ return g(p+0x14); }
