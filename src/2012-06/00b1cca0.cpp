// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
void __cdecl xfree(void*);
struct Base { char d[0x3c]; ~Base(); };
struct G : Base { void* p; ~G() { if (p) xfree(p); } };
G g;