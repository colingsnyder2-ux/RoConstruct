// from server: 100% by auto
// roc 2012-06 0094f230  unit: RBX::AdvRotateTool  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0094f230
//
// 0094f230  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0094f234  8b542408             mov edx, dword ptr [esp + 8]
// 0094f238  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0094f23c  3bca                 cmp ecx, edx
// 0094f23e  742c                 je 0x94f26c
// 0094f240  56                   push esi
// 0094f241  85c0                 test eax, eax
// 0094f243  741c                 je 0x94f261
// 0094f245  8b31                 mov esi, dword ptr [ecx]
// 0094f247  8930                 mov dword ptr [eax], esi
// 0094f249  8b7104               mov esi, dword ptr [ecx + 4]
// 0094f24c  897004               mov dword ptr [eax + 4], esi
// 0094f24f  8b7108               mov esi, dword ptr [ecx + 8]
// 0094f252  897008               mov dword ptr [eax + 8], esi
// 0094f255  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0094f258  89700c               mov dword ptr [eax + 0xc], esi
// 0094f25b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0094f25e  897010               mov dword ptr [eax + 0x10], esi
// 0094f261  83c114               add ecx, 0x14
// 0094f264  83c014               add eax, 0x14
// 0094f267  3bca                 cmp ecx, edx
// 0094f269  75d6                 jne 0x94f241
// 0094f26b  5e                   pop esi
// 0094f26c  c3                   ret 
// standard library vector<pod20> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
