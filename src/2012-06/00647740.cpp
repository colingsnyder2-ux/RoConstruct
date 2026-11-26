// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
void __declspec(dllimport) __cdecl imp(void*);
struct P { char p[0x54]; void* io; };
void f(P* p) { if (p) imp(p->io); }