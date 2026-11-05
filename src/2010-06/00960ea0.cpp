// from server: 100% by auto
// roc 2010-06 00960ea0  unit: RBX::SphereBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00960ea0
//
// 00960ea0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00960ea4  8b542408             mov edx, dword ptr [esp + 8]
// 00960ea8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00960eac  3bca                 cmp ecx, edx
// 00960eae  741a                 je 0x960eca
// 00960eb0  56                   push esi
// 00960eb1  85c0                 test eax, eax
// 00960eb3  740a                 je 0x960ebf
// 00960eb5  8b31                 mov esi, dword ptr [ecx]
// 00960eb7  8930                 mov dword ptr [eax], esi
// 00960eb9  8b7104               mov esi, dword ptr [ecx + 4]
// 00960ebc  897004               mov dword ptr [eax + 4], esi
// 00960ebf  83c108               add ecx, 8
// 00960ec2  83c008               add eax, 8
// 00960ec5  3bca                 cmp ecx, edx
// 00960ec7  75e8                 jne 0x960eb1
// 00960ec9  5e                   pop esi
// 00960eca  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
