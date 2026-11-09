// from server: 100% by auto
// roc 2009-06 00482eb0  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00482eb0
//
// 00482eb0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00482eb4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00482eb8  56                   push esi
// 00482eb9  8b742408             mov esi, dword ptr [esp + 8]
// 00482ebd  8bc1                 mov eax, ecx
// 00482ebf  2bc6                 sub eax, esi
// 00482ec1  c1f803               sar eax, 3
// 00482ec4  03c0                 add eax, eax
// 00482ec6  03c0                 add eax, eax
// 00482ec8  03c0                 add eax, eax
// 00482eca  57                   push edi
// 00482ecb  8bf8                 mov edi, eax
// 00482ecd  8bc2                 mov eax, edx
// 00482ecf  2bc7                 sub eax, edi
// 00482ed1  3bf1                 cmp esi, ecx
// 00482ed3  7416                 je 0x482eeb
// 00482ed5  2bd1                 sub edx, ecx
// 00482ed7  8b79f8               mov edi, dword ptr [ecx - 8]
// 00482eda  83e908               sub ecx, 8
// 00482edd  893c0a               mov dword ptr [edx + ecx], edi
// 00482ee0  8b7904               mov edi, dword ptr [ecx + 4]
// 00482ee3  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 00482ee7  3bce                 cmp ecx, esi
// 00482ee9  75ec                 jne 0x482ed7
// 00482eeb  5f                   pop edi
// 00482eec  5e                   pop esi
// 00482eed  c3                   ret 
// standard library vector<pod8> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
