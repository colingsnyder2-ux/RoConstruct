// from server: 100% by auto
// roc 2010-06 00904570  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904570
//
// 00904570  8b442404             mov eax, dword ptr [esp + 4]
// 00904574  8b542408             mov edx, dword ptr [esp + 8]
// 00904578  3bc2                 cmp eax, edx
// 0090457a  7423                 je 0x90459f
// 0090457c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00904580  56                   push esi
// 00904581  8b31                 mov esi, dword ptr [ecx]
// 00904583  8930                 mov dword ptr [eax], esi
// 00904585  8b7104               mov esi, dword ptr [ecx + 4]
// 00904588  897004               mov dword ptr [eax + 4], esi
// 0090458b  8b7108               mov esi, dword ptr [ecx + 8]
// 0090458e  897008               mov dword ptr [eax + 8], esi
// 00904591  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00904594  89700c               mov dword ptr [eax + 0xc], esi
// 00904597  83c010               add eax, 0x10
// 0090459a  3bc2                 cmp eax, edx
// 0090459c  75e3                 jne 0x904581
// 0090459e  5e                   pop esi
// 0090459f  c3                   ret 
// standard library vector<pod16> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
