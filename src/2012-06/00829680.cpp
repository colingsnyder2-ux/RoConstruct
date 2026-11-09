// from server: 100% by auto
// roc 2012-06 00829680  unit: RBX::BallBallContact  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00829680
//
// 00829680  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00829684  8b542408             mov edx, dword ptr [esp + 8]
// 00829688  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0082968c  3bca                 cmp ecx, edx
// 0082968e  741a                 je 0x8296aa
// 00829690  56                   push esi
// 00829691  85c0                 test eax, eax
// 00829693  740a                 je 0x82969f
// 00829695  8b31                 mov esi, dword ptr [ecx]
// 00829697  8930                 mov dword ptr [eax], esi
// 00829699  8b7104               mov esi, dword ptr [ecx + 4]
// 0082969c  897004               mov dword ptr [eax + 4], esi
// 0082969f  83c108               add ecx, 8
// 008296a2  83c008               add eax, 8
// 008296a5  3bca                 cmp ecx, edx
// 008296a7  75e8                 jne 0x829691
// 008296a9  5e                   pop esi
// 008296aa  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
