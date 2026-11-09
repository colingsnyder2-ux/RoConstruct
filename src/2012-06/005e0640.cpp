// from server: 100% by auto
// roc 2012-06 005e0640  unit: RBX::BeveledBlockBuilder  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005e0640
//
// 005e0640  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005e0644  8b542408             mov edx, dword ptr [esp + 8]
// 005e0648  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005e064c  3bca                 cmp ecx, edx
// 005e064e  7432                 je 0x5e0682
// 005e0650  56                   push esi
// 005e0651  85c0                 test eax, eax
// 005e0653  7422                 je 0x5e0677
// 005e0655  8b31                 mov esi, dword ptr [ecx]
// 005e0657  8930                 mov dword ptr [eax], esi
// 005e0659  8b7104               mov esi, dword ptr [ecx + 4]
// 005e065c  897004               mov dword ptr [eax + 4], esi
// 005e065f  8b7108               mov esi, dword ptr [ecx + 8]
// 005e0662  897008               mov dword ptr [eax + 8], esi
// 005e0665  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005e0668  89700c               mov dword ptr [eax + 0xc], esi
// 005e066b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005e066e  897010               mov dword ptr [eax + 0x10], esi
// 005e0671  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005e0674  897014               mov dword ptr [eax + 0x14], esi
// 005e0677  83c118               add ecx, 0x18
// 005e067a  83c018               add eax, 0x18
// 005e067d  3bca                 cmp ecx, edx
// 005e067f  75d0                 jne 0x5e0651
// 005e0681  5e                   pop esi
// 005e0682  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
