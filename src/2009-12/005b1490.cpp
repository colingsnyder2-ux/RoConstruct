// from server: 100% by auto
// roc 2009-12 005b1490  unit: RBX::BrickBuilder  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1490
//
// 005b1490  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b1494  8b542408             mov edx, dword ptr [esp + 8]
// 005b1498  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005b149c  3bca                 cmp ecx, edx
// 005b149e  7420                 je 0x5b14c0
// 005b14a0  56                   push esi
// 005b14a1  85c0                 test eax, eax
// 005b14a3  7410                 je 0x5b14b5
// 005b14a5  8b31                 mov esi, dword ptr [ecx]
// 005b14a7  8930                 mov dword ptr [eax], esi
// 005b14a9  8b7104               mov esi, dword ptr [ecx + 4]
// 005b14ac  897004               mov dword ptr [eax + 4], esi
// 005b14af  8b7108               mov esi, dword ptr [ecx + 8]
// 005b14b2  897008               mov dword ptr [eax + 8], esi
// 005b14b5  83c10c               add ecx, 0xc
// 005b14b8  83c00c               add eax, 0xc
// 005b14bb  3bca                 cmp ecx, edx
// 005b14bd  75e2                 jne 0x5b14a1
// 005b14bf  5e                   pop esi
// 005b14c0  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
