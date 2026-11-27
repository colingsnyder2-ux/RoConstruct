// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sig { void notify(void* p); };
static int g[4];
struct S { char pad[0xcc]; int value; char pad2[0x144-0xd0]; Sig sig; void set(int); };
void S::set(int v){ if (v != value) { value = v; sig.notify(&g); } }
