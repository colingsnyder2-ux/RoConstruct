// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
__declspec(dllimport) void __cdecl imp(void*);
struct V { void* p; int a; int b; void clear(); };
void V::clear() { if (p != 0) { imp(p); p = 0; } b = 0; a = 0; }