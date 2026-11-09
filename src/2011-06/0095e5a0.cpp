// from server: 100% by auto
// roc 2011-06 0095e5a0  unit: Ogre::RbxMeshPartAdapter  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0095e5a0
//
// 0095e5a0  8b442404             mov eax, dword ptr [esp + 4]
// 0095e5a4  8b542408             mov edx, dword ptr [esp + 8]
// 0095e5a8  3bc2                 cmp eax, edx
// 0095e5aa  7417                 je 0x95e5c3
// 0095e5ac  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0095e5b0  56                   push esi
// 0095e5b1  8b31                 mov esi, dword ptr [ecx]
// 0095e5b3  8930                 mov dword ptr [eax], esi
// 0095e5b5  8b7104               mov esi, dword ptr [ecx + 4]
// 0095e5b8  897004               mov dword ptr [eax + 4], esi
// 0095e5bb  83c008               add eax, 8
// 0095e5be  3bc2                 cmp eax, edx
// 0095e5c0  75ef                 jne 0x95e5b1
// 0095e5c2  5e                   pop esi
// 0095e5c3  c3                   ret 
// standard library vector<i64> (function ??$_Fill@PA_J_J@std@@YAXPA_J0AB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
