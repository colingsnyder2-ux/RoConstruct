// from server: 100% by auto
// roc 2011-06 007460a0  unit: RBX::Animator  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007460a0
//
// 007460a0  8b542404             mov edx, dword ptr [esp + 4]
// 007460a4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007460a8  53                   push ebx
// 007460a9  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007460ad  3bd3                 cmp edx, ebx
// 007460af  741d                 je 0x7460ce
// 007460b1  56                   push esi
// 007460b2  57                   push edi
// 007460b3  85c0                 test eax, eax
// 007460b5  740b                 je 0x7460c2
// 007460b7  b909000000           mov ecx, 9
// 007460bc  8bf2                 mov esi, edx
// 007460be  8bf8                 mov edi, eax
// 007460c0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007460c2  83c224               add edx, 0x24
// 007460c5  83c024               add eax, 0x24
// 007460c8  3bd3                 cmp edx, ebx
// 007460ca  75e7                 jne 0x7460b3
// 007460cc  5f                   pop edi
// 007460cd  5e                   pop esi
// 007460ce  5b                   pop ebx
// 007460cf  c3                   ret 
// standard library vector<pod36> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
