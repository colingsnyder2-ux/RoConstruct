// from server: 100% by auto
// roc 2012-06 0050d050  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050d050
//
// 0050d050  8b442404             mov eax, dword ptr [esp + 4]
// 0050d054  8b542408             mov edx, dword ptr [esp + 8]
// 0050d058  3bc2                 cmp eax, edx
// 0050d05a  7417                 je 0x50d073
// 0050d05c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0050d060  56                   push esi
// 0050d061  8b31                 mov esi, dword ptr [ecx]
// 0050d063  8930                 mov dword ptr [eax], esi
// 0050d065  8b7104               mov esi, dword ptr [ecx + 4]
// 0050d068  897004               mov dword ptr [eax + 4], esi
// 0050d06b  83c008               add eax, 8
// 0050d06e  3bc2                 cmp eax, edx
// 0050d070  75ef                 jne 0x50d061
// 0050d072  5e                   pop esi
// 0050d073  c3                   ret 
// standard library vector<i64> (function ??$_Fill@PA_J_J@std@@YAXPA_J0AB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
