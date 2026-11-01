// from server: 100% by auto
// roc 2009-12 0058b0c0  unit: RBX::BeveledBlockBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b0c0
//
// 0058b0c0  8b542408             mov edx, dword ptr [esp + 8]
// 0058b0c4  85d2                 test edx, edx
// 0058b0c6  7638                 jbe 0x58b100
// 0058b0c8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058b0cc  8b442404             mov eax, dword ptr [esp + 4]
// 0058b0d0  56                   push esi
// 0058b0d1  85c0                 test eax, eax
// 0058b0d3  7422                 je 0x58b0f7
// 0058b0d5  8b31                 mov esi, dword ptr [ecx]
// 0058b0d7  8930                 mov dword ptr [eax], esi
// 0058b0d9  8b7104               mov esi, dword ptr [ecx + 4]
// 0058b0dc  897004               mov dword ptr [eax + 4], esi
// 0058b0df  8b7108               mov esi, dword ptr [ecx + 8]
// 0058b0e2  897008               mov dword ptr [eax + 8], esi
// 0058b0e5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0058b0e8  89700c               mov dword ptr [eax + 0xc], esi
// 0058b0eb  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0058b0ee  897010               mov dword ptr [eax + 0x10], esi
// 0058b0f1  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0058b0f4  897014               mov dword ptr [eax + 0x14], esi
// 0058b0f7  4a                   dec edx
// 0058b0f8  83c018               add eax, 0x18
// 0058b0fb  85d2                 test edx, edx
// 0058b0fd  77d2                 ja 0x58b0d1
// 0058b0ff  5e                   pop esi
// 0058b100  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
