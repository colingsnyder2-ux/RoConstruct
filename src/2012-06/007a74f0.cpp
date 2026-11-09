// from server: 100% by auto
// roc 2012-06 007a74f0  unit: RBX::KeyframeSequence  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a74f0
//
// 007a74f0  8b542404             mov edx, dword ptr [esp + 4]
// 007a74f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a74f8  53                   push ebx
// 007a74f9  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007a74fd  3bd3                 cmp edx, ebx
// 007a74ff  741d                 je 0x7a751e
// 007a7501  56                   push esi
// 007a7502  57                   push edi
// 007a7503  85c0                 test eax, eax
// 007a7505  740b                 je 0x7a7512
// 007a7507  b908000000           mov ecx, 8
// 007a750c  8bf2                 mov esi, edx
// 007a750e  8bf8                 mov edi, eax
// 007a7510  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007a7512  83c220               add edx, 0x20
// 007a7515  83c020               add eax, 0x20
// 007a7518  3bd3                 cmp edx, ebx
// 007a751a  75e7                 jne 0x7a7503
// 007a751c  5f                   pop edi
// 007a751d  5e                   pop esi
// 007a751e  5b                   pop ebx
// 007a751f  c3                   ret 
// standard library vector<pod32> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
