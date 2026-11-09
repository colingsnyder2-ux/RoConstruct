// from server: 100% by auto
// roc 2011-06 00689c70  unit: RBX::Network::P8Player::?$GetSetImpl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00689c70
//
// 00689c70  8b542408             mov edx, dword ptr [esp + 8]
// 00689c74  85d2                 test edx, edx
// 00689c76  7625                 jbe 0x689c9d
// 00689c78  8b442404             mov eax, dword ptr [esp + 4]
// 00689c7c  53                   push ebx
// 00689c7d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00689c81  56                   push esi
// 00689c82  57                   push edi
// 00689c83  85c0                 test eax, eax
// 00689c85  740b                 je 0x689c92
// 00689c87  b908000000           mov ecx, 8
// 00689c8c  8bf3                 mov esi, ebx
// 00689c8e  8bf8                 mov edi, eax
// 00689c90  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00689c92  4a                   dec edx
// 00689c93  83c020               add eax, 0x20
// 00689c96  85d2                 test edx, edx
// 00689c98  77e9                 ja 0x689c83
// 00689c9a  5f                   pop edi
// 00689c9b  5e                   pop esi
// 00689c9c  5b                   pop ebx
// 00689c9d  c3                   ret 
// standard library vector<pod32> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
