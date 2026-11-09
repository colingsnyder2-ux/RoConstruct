// from server: 100% by auto
// roc 2012-06 007b25c0  unit: RBX::VCacheableContentProvider::?$NonFactoryProduct  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b25c0
//
// 007b25c0  8b542404             mov edx, dword ptr [esp + 4]
// 007b25c4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b25c8  53                   push ebx
// 007b25c9  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007b25cd  3bd3                 cmp edx, ebx
// 007b25cf  741d                 je 0x7b25ee
// 007b25d1  56                   push esi
// 007b25d2  57                   push edi
// 007b25d3  85c0                 test eax, eax
// 007b25d5  740b                 je 0x7b25e2
// 007b25d7  b909000000           mov ecx, 9
// 007b25dc  8bf2                 mov esi, edx
// 007b25de  8bf8                 mov edi, eax
// 007b25e0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007b25e2  83c224               add edx, 0x24
// 007b25e5  83c024               add eax, 0x24
// 007b25e8  3bd3                 cmp edx, ebx
// 007b25ea  75e7                 jne 0x7b25d3
// 007b25ec  5f                   pop edi
// 007b25ed  5e                   pop esi
// 007b25ee  5b                   pop ebx
// 007b25ef  c3                   ret 
// standard library vector<pod36> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
