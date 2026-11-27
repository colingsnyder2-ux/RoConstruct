// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*,long,long,const char*); struct E{char d[16]; __declspec(dllimport) E();}; __declspec(noreturn) void __cdecl thr(E*, void*); void f(long a,long b){ if(!CreateSemaphoreA(0,a,b,0)){ E e; thr(&e,(void*)0xcd6fe8);} }
