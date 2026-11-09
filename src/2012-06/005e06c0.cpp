// from server: 100% by auto
// roc 2012-06 005e06c0  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005e06c0
//
// 005e06c0  8b542408             mov edx, dword ptr [esp + 8]
// 005e06c4  85d2                 test edx, edx
// 005e06c6  7638                 jbe 0x5e0700
// 005e06c8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005e06cc  8b442404             mov eax, dword ptr [esp + 4]
// 005e06d0  56                   push esi
// 005e06d1  85c0                 test eax, eax
// 005e06d3  7422                 je 0x5e06f7
// 005e06d5  8b31                 mov esi, dword ptr [ecx]
// 005e06d7  8930                 mov dword ptr [eax], esi
// 005e06d9  8b7104               mov esi, dword ptr [ecx + 4]
// 005e06dc  897004               mov dword ptr [eax + 4], esi
// 005e06df  8b7108               mov esi, dword ptr [ecx + 8]
// 005e06e2  897008               mov dword ptr [eax + 8], esi
// 005e06e5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005e06e8  89700c               mov dword ptr [eax + 0xc], esi
// 005e06eb  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005e06ee  897010               mov dword ptr [eax + 0x10], esi
// 005e06f1  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005e06f4  897014               mov dword ptr [eax + 0x14], esi
// 005e06f7  4a                   dec edx
// 005e06f8  83c018               add eax, 0x18
// 005e06fb  85d2                 test edx, edx
// 005e06fd  77d2                 ja 0x5e06d1
// 005e06ff  5e                   pop esi
// 005e0700  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
