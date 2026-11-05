// from server: 100% by auto
// roc 2009-12 0058b010  unit: RBX::BeveledBlockBuilder  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b010
//
// 0058b010  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0058b014  8b542408             mov edx, dword ptr [esp + 8]
// 0058b018  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058b01c  3bca                 cmp ecx, edx
// 0058b01e  7432                 je 0x58b052
// 0058b020  56                   push esi
// 0058b021  85c0                 test eax, eax
// 0058b023  7422                 je 0x58b047
// 0058b025  8b31                 mov esi, dword ptr [ecx]
// 0058b027  8930                 mov dword ptr [eax], esi
// 0058b029  8b7104               mov esi, dword ptr [ecx + 4]
// 0058b02c  897004               mov dword ptr [eax + 4], esi
// 0058b02f  8b7108               mov esi, dword ptr [ecx + 8]
// 0058b032  897008               mov dword ptr [eax + 8], esi
// 0058b035  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0058b038  89700c               mov dword ptr [eax + 0xc], esi
// 0058b03b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0058b03e  897010               mov dword ptr [eax + 0x10], esi
// 0058b041  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0058b044  897014               mov dword ptr [eax + 0x14], esi
// 0058b047  83c118               add ecx, 0x18
// 0058b04a  83c018               add eax, 0x18
// 0058b04d  3bca                 cmp ecx, edx
// 0058b04f  75d0                 jne 0x58b021
// 0058b051  5e                   pop esi
// 0058b052  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
