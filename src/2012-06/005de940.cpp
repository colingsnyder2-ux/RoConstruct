// from server: 100% by auto
// roc 2012-06 005de940  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005de940
//
// 005de940  8b542404             mov edx, dword ptr [esp + 4]
// 005de944  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005de948  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005de94c  3bd1                 cmp edx, ecx
// 005de94e  7430                 je 0x5de980
// 005de950  56                   push esi
// 005de951  8b71e8               mov esi, dword ptr [ecx - 0x18]
// 005de954  83e918               sub ecx, 0x18
// 005de957  8970e8               mov dword ptr [eax - 0x18], esi
// 005de95a  8b7104               mov esi, dword ptr [ecx + 4]
// 005de95d  83e818               sub eax, 0x18
// 005de960  897004               mov dword ptr [eax + 4], esi
// 005de963  8b7108               mov esi, dword ptr [ecx + 8]
// 005de966  897008               mov dword ptr [eax + 8], esi
// 005de969  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005de96c  89700c               mov dword ptr [eax + 0xc], esi
// 005de96f  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005de972  897010               mov dword ptr [eax + 0x10], esi
// 005de975  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005de978  897014               mov dword ptr [eax + 0x14], esi
// 005de97b  3bca                 cmp ecx, edx
// 005de97d  75d2                 jne 0x5de951
// 005de97f  5e                   pop esi
// 005de980  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
