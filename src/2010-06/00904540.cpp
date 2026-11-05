// from server: 100% by auto
// roc 2010-06 00904540  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904540
//
// 00904540  8b442404             mov eax, dword ptr [esp + 4]
// 00904544  8b542408             mov edx, dword ptr [esp + 8]
// 00904548  3bc2                 cmp eax, edx
// 0090454a  7417                 je 0x904563
// 0090454c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00904550  56                   push esi
// 00904551  8b31                 mov esi, dword ptr [ecx]
// 00904553  8930                 mov dword ptr [eax], esi
// 00904555  8b7104               mov esi, dword ptr [ecx + 4]
// 00904558  897004               mov dword ptr [eax + 4], esi
// 0090455b  83c008               add eax, 8
// 0090455e  3bc2                 cmp eax, edx
// 00904560  75ef                 jne 0x904551
// 00904562  5e                   pop esi
// 00904563  c3                   ret 
// standard library vector<i64> (function ??$_Fill@PA_J_J@std@@YAXPA_J0AB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
