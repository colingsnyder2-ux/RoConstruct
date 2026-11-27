// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
__declspec(dllimport) int __stdcall Fn(void*); struct S{ void** h; bool on; void f(); }; void S::f(){ if(on){ Fn(*h); on=false; } }
