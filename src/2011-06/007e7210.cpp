// from server: 100% by auto
// roc 2011-06 007e7210  unit: RBX::AdvRotateTool  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e7210
//
// 007e7210  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e7214  8b542408             mov edx, dword ptr [esp + 8]
// 007e7218  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e721c  3bca                 cmp ecx, edx
// 007e721e  742c                 je 0x7e724c
// 007e7220  56                   push esi
// 007e7221  85c0                 test eax, eax
// 007e7223  741c                 je 0x7e7241
// 007e7225  8b31                 mov esi, dword ptr [ecx]
// 007e7227  8930                 mov dword ptr [eax], esi
// 007e7229  8b7104               mov esi, dword ptr [ecx + 4]
// 007e722c  897004               mov dword ptr [eax + 4], esi
// 007e722f  8b7108               mov esi, dword ptr [ecx + 8]
// 007e7232  897008               mov dword ptr [eax + 8], esi
// 007e7235  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007e7238  89700c               mov dword ptr [eax + 0xc], esi
// 007e723b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007e723e  897010               mov dword ptr [eax + 0x10], esi
// 007e7241  83c114               add ecx, 0x14
// 007e7244  83c014               add eax, 0x14
// 007e7247  3bca                 cmp ecx, edx
// 007e7249  75d6                 jne 0x7e7221
// 007e724b  5e                   pop esi
// 007e724c  c3                   ret 
// standard library vector<pod20> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
