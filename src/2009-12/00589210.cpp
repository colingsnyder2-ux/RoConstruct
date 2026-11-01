// from server: 100% by auto
// roc 2009-12 00589210  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00589210
//
// 00589210  8b542404             mov edx, dword ptr [esp + 4]
// 00589214  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00589218  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058921c  3bd1                 cmp edx, ecx
// 0058921e  7430                 je 0x589250
// 00589220  56                   push esi
// 00589221  8b71e8               mov esi, dword ptr [ecx - 0x18]
// 00589224  83e918               sub ecx, 0x18
// 00589227  8970e8               mov dword ptr [eax - 0x18], esi
// 0058922a  8b7104               mov esi, dword ptr [ecx + 4]
// 0058922d  83e818               sub eax, 0x18
// 00589230  897004               mov dword ptr [eax + 4], esi
// 00589233  8b7108               mov esi, dword ptr [ecx + 8]
// 00589236  897008               mov dword ptr [eax + 8], esi
// 00589239  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0058923c  89700c               mov dword ptr [eax + 0xc], esi
// 0058923f  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00589242  897010               mov dword ptr [eax + 0x10], esi
// 00589245  8b7114               mov esi, dword ptr [ecx + 0x14]
// 00589248  897014               mov dword ptr [eax + 0x14], esi
// 0058924b  3bca                 cmp ecx, edx
// 0058924d  75d2                 jne 0x589221
// 0058924f  5e                   pop esi
// 00589250  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
