// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct S { char pad[0x10]; void* cs; char pad2[8]; int v; };
int __stdcall f(S* s, int value) { void* c = s->cs; EnterCriticalSection(c); s->v = value; LeaveCriticalSection(c); return 0; }
