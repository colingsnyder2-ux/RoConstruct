// from server: 100% by auto
// roc 2012-06 0050d080  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050d080
//
// 0050d080  8b442404             mov eax, dword ptr [esp + 4]
// 0050d084  8b542408             mov edx, dword ptr [esp + 8]
// 0050d088  3bc2                 cmp eax, edx
// 0050d08a  7423                 je 0x50d0af
// 0050d08c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0050d090  56                   push esi
// 0050d091  8b31                 mov esi, dword ptr [ecx]
// 0050d093  8930                 mov dword ptr [eax], esi
// 0050d095  8b7104               mov esi, dword ptr [ecx + 4]
// 0050d098  897004               mov dword ptr [eax + 4], esi
// 0050d09b  8b7108               mov esi, dword ptr [ecx + 8]
// 0050d09e  897008               mov dword ptr [eax + 8], esi
// 0050d0a1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0050d0a4  89700c               mov dword ptr [eax + 0xc], esi
// 0050d0a7  83c010               add eax, 0x10
// 0050d0aa  3bc2                 cmp eax, edx
// 0050d0ac  75e3                 jne 0x50d091
// 0050d0ae  5e                   pop esi
// 0050d0af  c3                   ret 
// standard library vector<pod16> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
