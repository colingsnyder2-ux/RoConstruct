// from server: 83% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Fl { bool a, b; Fl() { a = true; } };
struct Holder { int x; Fl f; };
extern void __cdecl tgt();
extern void __cdecl g(void (__cdecl *)(), Fl);
void h() { Holder h; g(tgt, h.f); }