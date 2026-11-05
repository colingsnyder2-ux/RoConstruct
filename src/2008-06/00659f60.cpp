// from server: 100% by auto
// roc 2008-06 00659f60  unit: RBX::BallBallContact  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00659f60
//
// 00659f60  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00659f64  8b542408             mov edx, dword ptr [esp + 8]
// 00659f68  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00659f6c  3bca                 cmp ecx, edx
// 00659f6e  741a                 je 0x659f8a
// 00659f70  56                   push esi
// 00659f71  85c0                 test eax, eax
// 00659f73  740a                 je 0x659f7f
// 00659f75  8b31                 mov esi, dword ptr [ecx]
// 00659f77  8930                 mov dword ptr [eax], esi
// 00659f79  8b7104               mov esi, dword ptr [ecx + 4]
// 00659f7c  897004               mov dword ptr [eax + 4], esi
// 00659f7f  83c108               add ecx, 8
// 00659f82  83c008               add eax, 8
// 00659f85  3bca                 cmp ecx, edx
// 00659f87  75e8                 jne 0x659f71
// 00659f89  5e                   pop esi
// 00659f8a  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
