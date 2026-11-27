// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sig { void notify(void* p); };
static int g[4];
struct S { char pad[224]; bool value; char pad2[324-224-sizeof(bool)]; Sig sig; void set(bool); };
void S::set(bool v){ if (v != value) { value = v; sig.notify(&g); } }
