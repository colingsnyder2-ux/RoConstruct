// from server: 87% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern bool g;
__declspec(dllimport) void __cdecl imp();
void f() { if (g) imp(); }