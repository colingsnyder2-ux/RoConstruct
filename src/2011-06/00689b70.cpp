// from server: 100% by auto
// roc 2011-06 00689b70  unit: RBX::Network::P8Player::?$GetSetImpl  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00689b70
//
// 00689b70  8b542404             mov edx, dword ptr [esp + 4]
// 00689b74  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00689b78  53                   push ebx
// 00689b79  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00689b7d  3bd3                 cmp edx, ebx
// 00689b7f  741d                 je 0x689b9e
// 00689b81  56                   push esi
// 00689b82  57                   push edi
// 00689b83  85c0                 test eax, eax
// 00689b85  740b                 je 0x689b92
// 00689b87  b908000000           mov ecx, 8
// 00689b8c  8bf2                 mov esi, edx
// 00689b8e  8bf8                 mov edi, eax
// 00689b90  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00689b92  83c220               add edx, 0x20
// 00689b95  83c020               add eax, 0x20
// 00689b98  3bd3                 cmp edx, ebx
// 00689b9a  75e7                 jne 0x689b83
// 00689b9c  5f                   pop edi
// 00689b9d  5e                   pop esi
// 00689b9e  5b                   pop ebx
// 00689b9f  c3                   ret 
// standard library vector<pod32> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
