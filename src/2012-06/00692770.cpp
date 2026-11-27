// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
int __stdcall chk(const void*, bool*);
struct C { char pad[0x88]; const void* p; char pad2[0x30]; int n; bool f(); };
bool C::f() { if (!p) return n > 0; bool b; return chk(p, &b) == 0x24 ? false : b; }
