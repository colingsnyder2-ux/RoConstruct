// from server: 100% by auto
// roc 2009-12 00589190  unit: RBX::BeveledBlockBuilder  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00589190
//
// 00589190  8b442404             mov eax, dword ptr [esp + 4]
// 00589194  8b542408             mov edx, dword ptr [esp + 8]
// 00589198  3bc2                 cmp eax, edx
// 0058919a  742f                 je 0x5891cb
// 0058919c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005891a0  56                   push esi
// 005891a1  8b31                 mov esi, dword ptr [ecx]
// 005891a3  8930                 mov dword ptr [eax], esi
// 005891a5  8b7104               mov esi, dword ptr [ecx + 4]
// 005891a8  897004               mov dword ptr [eax + 4], esi
// 005891ab  8b7108               mov esi, dword ptr [ecx + 8]
// 005891ae  897008               mov dword ptr [eax + 8], esi
// 005891b1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005891b4  89700c               mov dword ptr [eax + 0xc], esi
// 005891b7  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005891ba  897010               mov dword ptr [eax + 0x10], esi
// 005891bd  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005891c0  897014               mov dword ptr [eax + 0x14], esi
// 005891c3  83c018               add eax, 0x18
// 005891c6  3bc2                 cmp eax, edx
// 005891c8  75d7                 jne 0x5891a1
// 005891ca  5e                   pop esi
// 005891cb  c3                   ret 
// standard library vector<pod24> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
