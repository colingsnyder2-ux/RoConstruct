// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern void __cdecl fr(void*);
struct Base { char pad[0x3c]; ~Base(); };
struct G : Base { void* a; void* b; void* c; void* d; void* e;
  ~G() { fr(e); fr(d); fr(c); fr(b); fr(a); } };
static G g;