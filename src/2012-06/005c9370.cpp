// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall imp(int);
struct S{ int h; void m(); }; void S::m(){ if(h!=-1){ imp(h); h=-1; } }
