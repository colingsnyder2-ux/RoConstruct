// from server: 100% by auto
// roc 2009-06 00530bd0  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00530bd0
//
// 00530bd0  8b542404             mov edx, dword ptr [esp + 4]
// 00530bd4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00530bd8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00530bdc  3bd1                 cmp edx, ecx
// 00530bde  7430                 je 0x530c10
// 00530be0  56                   push esi
// 00530be1  8b71e8               mov esi, dword ptr [ecx - 0x18]
// 00530be4  83e918               sub ecx, 0x18
// 00530be7  8970e8               mov dword ptr [eax - 0x18], esi
// 00530bea  8b7104               mov esi, dword ptr [ecx + 4]
// 00530bed  83e818               sub eax, 0x18
// 00530bf0  897004               mov dword ptr [eax + 4], esi
// 00530bf3  8b7108               mov esi, dword ptr [ecx + 8]
// 00530bf6  897008               mov dword ptr [eax + 8], esi
// 00530bf9  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00530bfc  89700c               mov dword ptr [eax + 0xc], esi
// 00530bff  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00530c02  897010               mov dword ptr [eax + 0x10], esi
// 00530c05  8b7114               mov esi, dword ptr [ecx + 0x14]
// 00530c08  897014               mov dword ptr [eax + 0x14], esi
// 00530c0b  3bca                 cmp ecx, edx
// 00530c0d  75d2                 jne 0x530be1
// 00530c0f  5e                   pop esi
// 00530c10  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
