// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub { void reset(); };
struct MI { char pad[0x90]; Sub s; char pad2[0xc4-0x91]; int z; void f(void* p); void base(void* p); };
void MI::f(void* p) { base(p); z = 0; s.reset(); }
