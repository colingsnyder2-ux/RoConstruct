// from server: 100% by auto
// roc 2011-06 0097cef0  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0097cef0
//
// 0097cef0  8b542404             mov edx, dword ptr [esp + 4]
// 0097cef4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0097cef8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0097cefc  3bd1                 cmp edx, ecx
// 0097cefe  7430                 je 0x97cf30
// 0097cf00  56                   push esi
// 0097cf01  8b71e8               mov esi, dword ptr [ecx - 0x18]
// 0097cf04  83e918               sub ecx, 0x18
// 0097cf07  8970e8               mov dword ptr [eax - 0x18], esi
// 0097cf0a  8b7104               mov esi, dword ptr [ecx + 4]
// 0097cf0d  83e818               sub eax, 0x18
// 0097cf10  897004               mov dword ptr [eax + 4], esi
// 0097cf13  8b7108               mov esi, dword ptr [ecx + 8]
// 0097cf16  897008               mov dword ptr [eax + 8], esi
// 0097cf19  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0097cf1c  89700c               mov dword ptr [eax + 0xc], esi
// 0097cf1f  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0097cf22  897010               mov dword ptr [eax + 0x10], esi
// 0097cf25  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0097cf28  897014               mov dword ptr [eax + 0x14], esi
// 0097cf2b  3bca                 cmp ecx, edx
// 0097cf2d  75d2                 jne 0x97cf01
// 0097cf2f  5e                   pop esi
// 0097cf30  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
