// from server: 100% by auto
// roc 2010-06 009043f0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009043f0
//
// 009043f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009043f4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 009043f8  56                   push esi
// 009043f9  8b742408             mov esi, dword ptr [esp + 8]
// 009043fd  8bc1                 mov eax, ecx
// 009043ff  2bc6                 sub eax, esi
// 00904401  c1f804               sar eax, 4
// 00904404  c1e004               shl eax, 4
// 00904407  57                   push edi
// 00904408  8bf8                 mov edi, eax
// 0090440a  8bc2                 mov eax, edx
// 0090440c  2bc7                 sub eax, edi
// 0090440e  3bf1                 cmp esi, ecx
// 00904410  7424                 je 0x904436
// 00904412  2bd1                 sub edx, ecx
// 00904414  8b79f0               mov edi, dword ptr [ecx - 0x10]
// 00904417  83e910               sub ecx, 0x10
// 0090441a  893c0a               mov dword ptr [edx + ecx], edi
// 0090441d  8b7904               mov edi, dword ptr [ecx + 4]
// 00904420  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 00904424  8b7908               mov edi, dword ptr [ecx + 8]
// 00904427  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 0090442b  8b790c               mov edi, dword ptr [ecx + 0xc]
// 0090442e  897c0a0c             mov dword ptr [edx + ecx + 0xc], edi
// 00904432  3bce                 cmp ecx, esi
// 00904434  75de                 jne 0x904414
// 00904436  5f                   pop edi
// 00904437  5e                   pop esi
// 00904438  c3                   ret 
// standard library vector<pod16> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
