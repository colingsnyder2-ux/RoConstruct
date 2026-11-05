// from server: 100% by auto
// roc 2011-06 0097ec20  unit: RBX::BeveledBlockBuilder  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0097ec20
//
// 0097ec20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0097ec24  8b542408             mov edx, dword ptr [esp + 8]
// 0097ec28  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0097ec2c  3bca                 cmp ecx, edx
// 0097ec2e  7432                 je 0x97ec62
// 0097ec30  56                   push esi
// 0097ec31  85c0                 test eax, eax
// 0097ec33  7422                 je 0x97ec57
// 0097ec35  8b31                 mov esi, dword ptr [ecx]
// 0097ec37  8930                 mov dword ptr [eax], esi
// 0097ec39  8b7104               mov esi, dword ptr [ecx + 4]
// 0097ec3c  897004               mov dword ptr [eax + 4], esi
// 0097ec3f  8b7108               mov esi, dword ptr [ecx + 8]
// 0097ec42  897008               mov dword ptr [eax + 8], esi
// 0097ec45  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0097ec48  89700c               mov dword ptr [eax + 0xc], esi
// 0097ec4b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0097ec4e  897010               mov dword ptr [eax + 0x10], esi
// 0097ec51  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0097ec54  897014               mov dword ptr [eax + 0x14], esi
// 0097ec57  83c118               add ecx, 0x18
// 0097ec5a  83c018               add eax, 0x18
// 0097ec5d  3bca                 cmp ecx, edx
// 0097ec5f  75d0                 jne 0x97ec31
// 0097ec61  5e                   pop esi
// 0097ec62  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
