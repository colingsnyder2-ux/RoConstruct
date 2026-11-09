// from server: 100% by auto
// roc 2010-06 00787110  unit: RBX::HUMAN::GettingUp  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787110
//
// 00787110  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00787114  8b542408             mov edx, dword ptr [esp + 8]
// 00787118  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078711c  3bca                 cmp ecx, edx
// 0078711e  742c                 je 0x78714c
// 00787120  56                   push esi
// 00787121  85c0                 test eax, eax
// 00787123  741c                 je 0x787141
// 00787125  8b31                 mov esi, dword ptr [ecx]
// 00787127  8930                 mov dword ptr [eax], esi
// 00787129  8b7104               mov esi, dword ptr [ecx + 4]
// 0078712c  897004               mov dword ptr [eax + 4], esi
// 0078712f  8b7108               mov esi, dword ptr [ecx + 8]
// 00787132  897008               mov dword ptr [eax + 8], esi
// 00787135  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00787138  89700c               mov dword ptr [eax + 0xc], esi
// 0078713b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0078713e  897010               mov dword ptr [eax + 0x10], esi
// 00787141  83c114               add ecx, 0x14
// 00787144  83c014               add eax, 0x14
// 00787147  3bca                 cmp ecx, edx
// 00787149  75d6                 jne 0x787121
// 0078714b  5e                   pop esi
// 0078714c  c3                   ret 
// standard library vector<pod20> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
