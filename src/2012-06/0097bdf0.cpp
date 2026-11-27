// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
__declspec(dllimport) int __stdcall Fn(void*); void g(); void __fastcall f(void** p){ if(*p && !Fn(*p)) g(); }
