// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
#pragma optimize("g", off)
struct VChunk{char pad[0x15];}; char* f(VChunk* p){return p->pad+0x15;}
