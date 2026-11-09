// from server: 100% by auto
// roc 2012-06 005de900  unit: RBX::BeveledBlockBuilder  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005de900
//
// 005de900  8b442404             mov eax, dword ptr [esp + 4]
// 005de904  8b542408             mov edx, dword ptr [esp + 8]
// 005de908  3bc2                 cmp eax, edx
// 005de90a  742f                 je 0x5de93b
// 005de90c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005de910  56                   push esi
// 005de911  8b31                 mov esi, dword ptr [ecx]
// 005de913  8930                 mov dword ptr [eax], esi
// 005de915  8b7104               mov esi, dword ptr [ecx + 4]
// 005de918  897004               mov dword ptr [eax + 4], esi
// 005de91b  8b7108               mov esi, dword ptr [ecx + 8]
// 005de91e  897008               mov dword ptr [eax + 8], esi
// 005de921  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005de924  89700c               mov dword ptr [eax + 0xc], esi
// 005de927  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005de92a  897010               mov dword ptr [eax + 0x10], esi
// 005de92d  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005de930  897014               mov dword ptr [eax + 0x14], esi
// 005de933  83c018               add eax, 0x18
// 005de936  3bc2                 cmp eax, edx
// 005de938  75d7                 jne 0x5de911
// 005de93a  5e                   pop esi
// 005de93b  c3                   ret 
// standard library vector<pod24> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
