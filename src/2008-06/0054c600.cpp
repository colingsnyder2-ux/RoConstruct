// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
#pragma optimize("g", off)
struct VChunk{char pad[0x2d];}; char* f(VChunk* p){return p->pad+0x2d;}
