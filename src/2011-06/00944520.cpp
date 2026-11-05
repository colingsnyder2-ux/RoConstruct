// from server: 100% by auto
// roc 2011-06 00944520  unit: Ogre::RbxTypesetter  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00944520
//
// 00944520  8b442404             mov eax, dword ptr [esp + 4]
// 00944524  8b542408             mov edx, dword ptr [esp + 8]
// 00944528  3bc2                 cmp eax, edx
// 0094452a  741d                 je 0x944549
// 0094452c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00944530  56                   push esi
// 00944531  8b31                 mov esi, dword ptr [ecx]
// 00944533  8930                 mov dword ptr [eax], esi
// 00944535  8b7104               mov esi, dword ptr [ecx + 4]
// 00944538  897004               mov dword ptr [eax + 4], esi
// 0094453b  8b7108               mov esi, dword ptr [ecx + 8]
// 0094453e  897008               mov dword ptr [eax + 8], esi
// 00944541  83c00c               add eax, 0xc
// 00944544  3bc2                 cmp eax, edx
// 00944546  75e9                 jne 0x944531
// 00944548  5e                   pop esi
// 00944549  c3                   ret 
// standard library vector<pod12> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
