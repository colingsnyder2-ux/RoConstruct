// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
#pragma optimize("g", off)
struct VChunk{char pad[0xc];}; char* f(VChunk* p){return p->pad+0xc;}
