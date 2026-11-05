// from server: 100% by auto
// roc 2009-12 005b1590  unit: RBX::BrickBuilder  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1590
//
// 005b1590  8b442404             mov eax, dword ptr [esp + 4]
// 005b1594  8b542408             mov edx, dword ptr [esp + 8]
// 005b1598  3bc2                 cmp eax, edx
// 005b159a  741d                 je 0x5b15b9
// 005b159c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b15a0  56                   push esi
// 005b15a1  8b31                 mov esi, dword ptr [ecx]
// 005b15a3  8930                 mov dword ptr [eax], esi
// 005b15a5  8b7104               mov esi, dword ptr [ecx + 4]
// 005b15a8  897004               mov dword ptr [eax + 4], esi
// 005b15ab  8b7108               mov esi, dword ptr [ecx + 8]
// 005b15ae  897008               mov dword ptr [eax + 8], esi
// 005b15b1  83c00c               add eax, 0xc
// 005b15b4  3bc2                 cmp eax, edx
// 005b15b6  75e9                 jne 0x5b15a1
// 005b15b8  5e                   pop esi
// 005b15b9  c3                   ret 
// standard library vector<pod12> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
