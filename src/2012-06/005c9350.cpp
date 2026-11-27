// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall imp(int,int,int,int);
struct S{ int h; void m(); }; void S::m(){ h=imp(0,0,0,0); }
