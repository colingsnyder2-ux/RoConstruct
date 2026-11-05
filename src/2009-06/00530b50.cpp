// from server: 100% by auto
// roc 2009-06 00530b50  unit: RBX::BeveledBlockBuilder  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00530b50
//
// 00530b50  8b442404             mov eax, dword ptr [esp + 4]
// 00530b54  8b542408             mov edx, dword ptr [esp + 8]
// 00530b58  3bc2                 cmp eax, edx
// 00530b5a  742f                 je 0x530b8b
// 00530b5c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00530b60  56                   push esi
// 00530b61  8b31                 mov esi, dword ptr [ecx]
// 00530b63  8930                 mov dword ptr [eax], esi
// 00530b65  8b7104               mov esi, dword ptr [ecx + 4]
// 00530b68  897004               mov dword ptr [eax + 4], esi
// 00530b6b  8b7108               mov esi, dword ptr [ecx + 8]
// 00530b6e  897008               mov dword ptr [eax + 8], esi
// 00530b71  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00530b74  89700c               mov dword ptr [eax + 0xc], esi
// 00530b77  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00530b7a  897010               mov dword ptr [eax + 0x10], esi
// 00530b7d  8b7114               mov esi, dword ptr [ecx + 0x14]
// 00530b80  897014               mov dword ptr [eax + 0x14], esi
// 00530b83  83c018               add eax, 0x18
// 00530b86  3bc2                 cmp eax, edx
// 00530b88  75d7                 jne 0x530b61
// 00530b8a  5e                   pop esi
// 00530b8b  c3                   ret 
// standard library vector<pod24> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
