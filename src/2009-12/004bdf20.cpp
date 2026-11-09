// from server: 100% by auto
// roc 2009-12 004bdf20  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bdf20
//
// 004bdf20  8b442404             mov eax, dword ptr [esp + 4]
// 004bdf24  8b542408             mov edx, dword ptr [esp + 8]
// 004bdf28  3bc2                 cmp eax, edx
// 004bdf2a  7423                 je 0x4bdf4f
// 004bdf2c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004bdf30  56                   push esi
// 004bdf31  8b31                 mov esi, dword ptr [ecx]
// 004bdf33  8930                 mov dword ptr [eax], esi
// 004bdf35  8b7104               mov esi, dword ptr [ecx + 4]
// 004bdf38  897004               mov dword ptr [eax + 4], esi
// 004bdf3b  8b7108               mov esi, dword ptr [ecx + 8]
// 004bdf3e  897008               mov dword ptr [eax + 8], esi
// 004bdf41  8b710c               mov esi, dword ptr [ecx + 0xc]
// 004bdf44  89700c               mov dword ptr [eax + 0xc], esi
// 004bdf47  83c010               add eax, 0x10
// 004bdf4a  3bc2                 cmp eax, edx
// 004bdf4c  75e3                 jne 0x4bdf31
// 004bdf4e  5e                   pop esi
// 004bdf4f  c3                   ret 
// standard library vector<pod16> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
