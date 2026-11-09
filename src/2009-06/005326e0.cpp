// from server: 100% by auto
// roc 2009-06 005326e0  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005326e0
//
// 005326e0  8b542408             mov edx, dword ptr [esp + 8]
// 005326e4  85d2                 test edx, edx
// 005326e6  7638                 jbe 0x532720
// 005326e8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005326ec  8b442404             mov eax, dword ptr [esp + 4]
// 005326f0  56                   push esi
// 005326f1  85c0                 test eax, eax
// 005326f3  7422                 je 0x532717
// 005326f5  8b31                 mov esi, dword ptr [ecx]
// 005326f7  8930                 mov dword ptr [eax], esi
// 005326f9  8b7104               mov esi, dword ptr [ecx + 4]
// 005326fc  897004               mov dword ptr [eax + 4], esi
// 005326ff  8b7108               mov esi, dword ptr [ecx + 8]
// 00532702  897008               mov dword ptr [eax + 8], esi
// 00532705  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00532708  89700c               mov dword ptr [eax + 0xc], esi
// 0053270b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0053270e  897010               mov dword ptr [eax + 0x10], esi
// 00532711  8b7114               mov esi, dword ptr [ecx + 0x14]
// 00532714  897014               mov dword ptr [eax + 0x14], esi
// 00532717  4a                   dec edx
// 00532718  83c018               add eax, 0x18
// 0053271b  85d2                 test edx, edx
// 0053271d  77d2                 ja 0x5326f1
// 0053271f  5e                   pop esi
// 00532720  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
