// from server: 100% by auto
// roc 2012-06 007b25f0  unit: RBX::VCacheableContentProvider::?$NonFactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b25f0
//
// 007b25f0  8b542408             mov edx, dword ptr [esp + 8]
// 007b25f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b25f8  53                   push ebx
// 007b25f9  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007b25fd  3bda                 cmp ebx, edx
// 007b25ff  7419                 je 0x7b261a
// 007b2601  56                   push esi
// 007b2602  57                   push edi
// 007b2603  83ea24               sub edx, 0x24
// 007b2606  83e824               sub eax, 0x24
// 007b2609  b909000000           mov ecx, 9
// 007b260e  8bf2                 mov esi, edx
// 007b2610  8bf8                 mov edi, eax
// 007b2612  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007b2614  3bd3                 cmp edx, ebx
// 007b2616  75eb                 jne 0x7b2603
// 007b2618  5f                   pop edi
// 007b2619  5e                   pop esi
// 007b261a  5b                   pop ebx
// 007b261b  c3                   ret 
// standard library vector<pod36> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
