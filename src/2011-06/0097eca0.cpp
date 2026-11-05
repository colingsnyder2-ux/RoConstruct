// from server: 100% by auto
// roc 2011-06 0097eca0  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0097eca0
//
// 0097eca0  8b542408             mov edx, dword ptr [esp + 8]
// 0097eca4  85d2                 test edx, edx
// 0097eca6  7638                 jbe 0x97ece0
// 0097eca8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0097ecac  8b442404             mov eax, dword ptr [esp + 4]
// 0097ecb0  56                   push esi
// 0097ecb1  85c0                 test eax, eax
// 0097ecb3  7422                 je 0x97ecd7
// 0097ecb5  8b31                 mov esi, dword ptr [ecx]
// 0097ecb7  8930                 mov dword ptr [eax], esi
// 0097ecb9  8b7104               mov esi, dword ptr [ecx + 4]
// 0097ecbc  897004               mov dword ptr [eax + 4], esi
// 0097ecbf  8b7108               mov esi, dword ptr [ecx + 8]
// 0097ecc2  897008               mov dword ptr [eax + 8], esi
// 0097ecc5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0097ecc8  89700c               mov dword ptr [eax + 0xc], esi
// 0097eccb  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0097ecce  897010               mov dword ptr [eax + 0x10], esi
// 0097ecd1  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0097ecd4  897014               mov dword ptr [eax + 0x14], esi
// 0097ecd7  4a                   dec edx
// 0097ecd8  83c018               add eax, 0x18
// 0097ecdb  85d2                 test edx, edx
// 0097ecdd  77d2                 ja 0x97ecb1
// 0097ecdf  5e                   pop esi
// 0097ece0  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
