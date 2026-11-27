// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __cdecl imp(void*,const void*,unsigned);
void f(void* a,const void* b,unsigned c){ imp(a,b,c); }
