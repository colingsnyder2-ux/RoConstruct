// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
extern "C" __declspec(dllimport) void __cdecl free(void*);
void f(void* p) { if (p) free(p); }