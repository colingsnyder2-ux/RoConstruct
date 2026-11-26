// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
extern bool g;
__declspec(dllimport) void __cdecl imp();
void f() { if (g) imp(); }