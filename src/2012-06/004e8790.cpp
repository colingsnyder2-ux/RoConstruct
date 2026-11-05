// from server: 100% by auto
// roc 2012-06 004e8790  unit: Ogre::RbxTypesetter  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e8790
//
// 004e8790  8b442404             mov eax, dword ptr [esp + 4]
// 004e8794  8b542408             mov edx, dword ptr [esp + 8]
// 004e8798  3bc2                 cmp eax, edx
// 004e879a  741d                 je 0x4e87b9
// 004e879c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e87a0  56                   push esi
// 004e87a1  8b31                 mov esi, dword ptr [ecx]
// 004e87a3  8930                 mov dword ptr [eax], esi
// 004e87a5  8b7104               mov esi, dword ptr [ecx + 4]
// 004e87a8  897004               mov dword ptr [eax + 4], esi
// 004e87ab  8b7108               mov esi, dword ptr [ecx + 8]
// 004e87ae  897008               mov dword ptr [eax + 8], esi
// 004e87b1  83c00c               add eax, 0xc
// 004e87b4  3bc2                 cmp eax, edx
// 004e87b6  75e9                 jne 0x4e87a1
// 004e87b8  5e                   pop esi
// 004e87b9  c3                   ret 
// standard library vector<pod12> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
