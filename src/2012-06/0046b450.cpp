// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub { void notify(const void* d); };
static int g;
struct S { char pad[0x101]; char v; char pad2[0x144-0x102]; Sub sub; void set(char x); };
void S::set(char x) { if (x != v) { v = x; sub.notify(&g); } }
