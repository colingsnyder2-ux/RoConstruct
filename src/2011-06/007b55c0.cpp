// from server: 100% by auto
// roc 2011-06 007b55c0  unit: RBX::TreeStage  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b55c0
//
// 007b55c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b55c4  8b542408             mov edx, dword ptr [esp + 8]
// 007b55c8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b55cc  3bca                 cmp ecx, edx
// 007b55ce  7426                 je 0x7b55f6
// 007b55d0  56                   push esi
// 007b55d1  85c0                 test eax, eax
// 007b55d3  7416                 je 0x7b55eb
// 007b55d5  8b31                 mov esi, dword ptr [ecx]
// 007b55d7  8930                 mov dword ptr [eax], esi
// 007b55d9  8b7104               mov esi, dword ptr [ecx + 4]
// 007b55dc  897004               mov dword ptr [eax + 4], esi
// 007b55df  8b7108               mov esi, dword ptr [ecx + 8]
// 007b55e2  897008               mov dword ptr [eax + 8], esi
// 007b55e5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007b55e8  89700c               mov dword ptr [eax + 0xc], esi
// 007b55eb  83c110               add ecx, 0x10
// 007b55ee  83c010               add eax, 0x10
// 007b55f1  3bca                 cmp ecx, edx
// 007b55f3  75dc                 jne 0x7b55d1
// 007b55f5  5e                   pop esi
// 007b55f6  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
