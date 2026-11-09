// from server: 100% by auto
// roc 2009-06 00482b70  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00482b70
//
// 00482b70  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00482b74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00482b78  56                   push esi
// 00482b79  8b742408             mov esi, dword ptr [esp + 8]
// 00482b7d  8bc1                 mov eax, ecx
// 00482b7f  2bc6                 sub eax, esi
// 00482b81  c1f804               sar eax, 4
// 00482b84  c1e004               shl eax, 4
// 00482b87  57                   push edi
// 00482b88  8bf8                 mov edi, eax
// 00482b8a  8bc2                 mov eax, edx
// 00482b8c  2bc7                 sub eax, edi
// 00482b8e  3bf1                 cmp esi, ecx
// 00482b90  7424                 je 0x482bb6
// 00482b92  2bd1                 sub edx, ecx
// 00482b94  8b79f0               mov edi, dword ptr [ecx - 0x10]
// 00482b97  83e910               sub ecx, 0x10
// 00482b9a  893c0a               mov dword ptr [edx + ecx], edi
// 00482b9d  8b7904               mov edi, dword ptr [ecx + 4]
// 00482ba0  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 00482ba4  8b7908               mov edi, dword ptr [ecx + 8]
// 00482ba7  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 00482bab  8b790c               mov edi, dword ptr [ecx + 0xc]
// 00482bae  897c0a0c             mov dword ptr [edx + ecx + 0xc], edi
// 00482bb2  3bce                 cmp ecx, esi
// 00482bb4  75de                 jne 0x482b94
// 00482bb6  5f                   pop edi
// 00482bb7  5e                   pop esi
// 00482bb8  c3                   ret 
// standard library vector<pod16> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
