// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
__declspec(dllimport) int __stdcall CloseHandle(void*);
struct C { char p[0xc]; void** a; void** b; void* h; void f(); };
void C::f() { CloseHandle(h); CloseHandle(*a); CloseHandle(*b); }
