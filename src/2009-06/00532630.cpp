// from server: 100% by auto
// roc 2009-06 00532630  unit: RBX::BeveledBlockBuilder  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532630
//
// 00532630  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00532634  8b542408             mov edx, dword ptr [esp + 8]
// 00532638  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0053263c  3bca                 cmp ecx, edx
// 0053263e  7432                 je 0x532672
// 00532640  56                   push esi
// 00532641  85c0                 test eax, eax
// 00532643  7422                 je 0x532667
// 00532645  8b31                 mov esi, dword ptr [ecx]
// 00532647  8930                 mov dword ptr [eax], esi
// 00532649  8b7104               mov esi, dword ptr [ecx + 4]
// 0053264c  897004               mov dword ptr [eax + 4], esi
// 0053264f  8b7108               mov esi, dword ptr [ecx + 8]
// 00532652  897008               mov dword ptr [eax + 8], esi
// 00532655  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00532658  89700c               mov dword ptr [eax + 0xc], esi
// 0053265b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0053265e  897010               mov dword ptr [eax + 0x10], esi
// 00532661  8b7114               mov esi, dword ptr [ecx + 0x14]
// 00532664  897014               mov dword ptr [eax + 0x14], esi
// 00532667  83c118               add ecx, 0x18
// 0053266a  83c018               add eax, 0x18
// 0053266d  3bca                 cmp ecx, edx
// 0053266f  75d0                 jne 0x532641
// 00532671  5e                   pop esi
// 00532672  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
